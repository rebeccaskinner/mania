#ifndef __LIST_H__
#define __LIST_H__

/* completely un-optimized linked-list structure */
struct linked_list
{
    struct linked_list* prev;
    struct linked_list* next;
    void* data;
};

typedef struct linked_list linked_list_t;
typedef void* (*list_elem_fun)(void* elem);
typedef void* (*list_fold_fun)(void* val, void* elem);

linked_list_t* list_get_tail(linked_list_t* list);
linked_list_t* list_get_head(linked_list_t* list);
linked_list_t* list_cons(linked_list_t* head, void* data);
linked_list_t* list_insert_tail(linked_list_t* head, void* data);
linked_list_t* list_elem_cons(linked_list_t* head, void* data);
linked_list_t* list_elem_append(linked_list_t* head, void* data);
linked_list_t* list_elem_rm(linked_list_t* elem);

void list_map(linked_list_t* list, list_elem_fun f);
void* list_foldr(linked_list_t* list, list_fold_fun f, void* init_val);

void list_free_data(linked_list_t* list);
void list_free_all(linked_list_t* list);
void list_destruct(linked_list_t* list, list_elem_fun f);
#endif
