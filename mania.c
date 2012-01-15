#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <SDL/SDL.h>
#include "mania.h"

static struct hsearch_data args_table;

static void args_init() __attribute__((constructor));
static int show_help(game_config_t*,const char*) __attribute__((noreturn));

inline static int hash_insert(struct hsearch_data* t, char* k, void* d)
{
    ENTRY etmp = {k,d};
    ENTRY* ret_ents;
    return hsearch_r(etmp,ENTER,&ret_ents,t);
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

static void args_init()
{
    memset(&args_table,0,sizeof(struct hsearch_data));
    hcreate_r(30,&args_table);
    hash_insert(&args_table,(char*)flag_help_long, (void*)show_help);
    hash_insert(&args_table,(char*)flag_help_short,(void*)show_help);
}

static int show_help(game_config_t* config UNUSED, const char* val)
{
    if(val) printf("Error: unrecognized value \"%s\"\n",val);

    printf("mania: a simple shooter game\n");
    printf("usage: mania [options]\n\n");
    printf("-h, --help\t\tShow this help message and exit\n");
    exit(0);
}

static int parse_flags(int argc, char** argv)
{
    for(char* arg; (arg = *argv); argv++)
    {
        flag_fun f = hash_flag_lookup(&args_table,arg);
        char* value = NULL;
        if(!f) continue;
        if(*(argv+1) && '-' != **(argv+1)) value = *(++argv);
        f(NULL,value);
    }

    return 0;
}

int main(int argc, char** argv)
{
    parse_flags(argc, argv);
    printf("...running game...\n");
    return 0;
}
