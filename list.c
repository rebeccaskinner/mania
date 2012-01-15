#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "mania.h"

// returns tail element of list, or NULL if no list given
linked_list_t* list_get_tail(linked_list_t* list)
{
    if(UNLIKELY(NULL == list)) return NULL;
    linked_list_t* i = list;
    for(; i->next; i = i->next);
    return i;
}

// returns head element of list, or NULL if no list given
linked_list_t* list_get_head(linked_list_t* list)
{
    if(UNLIKELY(NULL == list)) return NULL;
    linked_list_t* i = list;
    for(; i->prev; i = i->prev);
    return i;
}

// prepends element to list and returns new head
linked_list_t* list_cons(linked_list_t* head, void* data)
{
    linked_list_t* node = malloc(sizeof(linked_list_t));
    node->prev = NULL;
    node->next = list_get_head(head);
    node->data = data;
    return node;
}

// appends element to list and returns new tail
linked_list_t* list_insert_tail(linked_list_t* head, void* data)
{
    linked_list_t* node = malloc(sizeof(linked_list_t));
    node->next = NULL;
    node->prev = list_get_tail(head);
    node->data = data;
    return node;
}

// prepends element to the current list node, and returns it
linked_list_t* list_elem_cons(linked_list_t* head, void* data)
{
    linked_list_t* node = malloc(sizeof(linked_list_t));
    node->next = head;
    node->prev = (LIKELY(NULL != head))?head->prev:NULL;
    if(LIKELY(NULL != head)) head->prev = node;
    node->data = data;
    return node;
}

// append element to the current list node, and returns it
linked_list_t* list_elem_append(linked_list_t* head, void* data)
{
    linked_list_t* node = malloc(sizeof(linked_list_t));
    node->prev = head;
    node->next = (LIKELY(NULL != head))?head->next:NULL;
    if(LIKELY(NULL != head)) head->next = node;
    node->data = data;
    return node;
}

// removes the current element from the list and returns it
linked_list_t* list_elem_rm(linked_list_t* elem)
{
    if(UNLIKELY(NULL == elem)) return NULL;
    if(elem->prev) elem->prev->next = elem->next;
    if(elem->next) elem->next->prev = elem->prev;
    return elem;
}
