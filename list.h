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

linked_list_t* list_get_tail(linked_list_t* list);
linked_list_t* list_get_head(linked_list_t* list);
linked_list_t* list_cons(linked_list_t* head, void* data);
linked_list_t* list_insert_tail(linked_list_t* head, void* data);
linked_list_t* list_elem_cons(linked_list_t* head, void* data);
linked_list_t* list_elem_append(linked_list_t* head, void* data);
linked_list_t* list_elem_rm(linked_list_t* elem);
#endif
