#define _GNU_SOURCE
#include <stdlib.h>
#include <search.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "args.h"
#include "hash_utils.h"
#include "list.h"
#include "mania.h"

struct arg_cmd
{
    flag_fun f;
    char* help_text;
    linked_list_t* options;
};

static struct hsearch_data args_table;
static game_config_t* config = NULL;
static linked_list_t* options_list = NULL;

inline static void print_arg(struct arg_cmd* c)
{
    for(linked_list_t* f = c->options; f; f = f->next)
    {
        printf("%s%s",(char*)f->data,f->next?",":"");
    }
    printf("\t\t%s\n",c->help_text);
}

inline static struct arg_cmd* vcreate_option(const flag_fun f,
                                             const char* help_text,
                                             va_list al)
{
    struct arg_cmd* cmd = malloc(sizeof(struct arg_cmd));
    char* flag;
    cmd->f = f;
    cmd->help_text = strdup(help_text);
    while(1)
    {
        flag = va_arg(al,char*);
        if(!flag) break;
        cmd->options = list_elem_cons(cmd->options,flag);
    }

    return cmd;
}

inline static struct arg_cmd* create_option(const flag_fun f,
                                            const char* help_text,
                                            ...)
{
    struct arg_cmd* c;
    va_list al;
    va_start(al,help_text);
    c = vcreate_option(f,help_text,al);
    va_end(al);

    return c;
}

inline static void add_arg(const flag_fun f, const char* help_text, ...)
{
    va_list al;
    va_start(al,help_text);
    options_list = list_elem_cons(options_list,vcreate_option(f,help_text,al));
    va_end(al);
}

inline static flag_fun hash_flag_lookup(struct hsearch_data* t, char* k)
{
    flag_fun f = NULL;
    ENTRY etmp  = {k,0};
    ENTRY* erv;

    if(hsearch_r(etmp,FIND,&erv,t))
    {
        if(erv) f = erv->data; 
    }
    return f;
}

static int show_help(game_config_t* c UNUSED, const char* val)
{
    if(val) printf("Error: unrecognized value \"%s\"\n",val);

    printf("mania: a simple shooter game\n");
    printf("usage: mania [options]\n\n");
    for(linked_list_t* o = options_list; o; o = o->next)
    {
        print_arg(o->data);
    }
    exit(0);
}

static int set_width(game_config_t* c, const char* val)
{
    if(!c || !val) return 1;
    c->screen_width = atoi(val);
    return 0;
}

static int set_height(game_config_t* c, const char* val)
{
    if(!c || !val) return 1;
    c->screen_height = atoi(val);
    return 0;
}

static int set_dimensions(game_config_t* c, const char* val)
{
    int   r =    1;
    char* v = NULL;
    char* h = NULL;
    char* w = NULL;

    if(!c || !val) goto cleanup;
    v = strdup(val);
    w = strtok(v,"x");
    if(!w) goto cleanup;
    h = strtok(NULL,"x");
    if(!h) goto cleanup;
    r = set_width(c,w) & set_height(c,h);
cleanup:
    if(LIKELY(NULL != v)) free(v);

    return r;
}

int parse_flags(int argc, char** argv)
{
    int rv = 0;
    for(char* arg; (arg = *argv); argv++)
    {
        flag_fun f = hash_flag_lookup(&args_table,arg);
        char* value = NULL;
        if(!f) continue;
        if(*(argv+1) && '-' != **(argv+1)) value = *(++argv);
        rv |= f(config,value);
    }

    return rv;
}

static void insert_args()
{
    struct arg_cmd* arg;
    for(linked_list_t* opt = options_list; opt; opt = opt->next)
    {
        if(!(arg = opt->data)) continue;
        for(linked_list_t* flag = arg->options; flag; flag = flag->next)
        {
            hash_insert(&args_table,flag->data,arg->f);
        }
    }
}

void args_init(game_config_t* c)
{
    config = c;
    memset(&args_table,0,sizeof(struct hsearch_data));
    hcreate_r(30,&args_table);
    add_arg(show_help,"show this help message and exit","-?","--help",0);
    add_arg(set_width,"set the game window width","-w","--width",0);
    add_arg(set_height,"set the game window height","-h","--height",0);
    add_arg(set_dimensions,"set the game window size (WxH)","-s","--size",0);
    insert_args();
}
