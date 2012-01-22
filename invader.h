#ifndef __INVADER_H__
#define __INVADER_H__

#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "utils.h"
#include "coords.h"
#include "mania.h"
#include "entity.h"

#define INVADER_ENTITY(inv) (&(inv->entity))
#define invader_draw(inv,st,surf) entity_draw(INVADER_ENTITY((inv)),(st),(surf))
#define invader_update(inv,st) entity_update(INVADER_ENTITY((inv)),(st))

struct invader
{
    entity_t entity;
    vector_t move_dir;
};

typedef struct invader invader_t;

invader_t* invader_new();

#endif
