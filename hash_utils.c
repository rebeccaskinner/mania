#define _GNU_SOURCE
#include <search.h>
#include "mania.h"

int hash_insert(struct hsearch_data* t, char* k, void* d)
{
    ENTRY etmp = {k,d};
    ENTRY* ret_ents;
    return hsearch_r(etmp,ENTER,&ret_ents,t);
}

