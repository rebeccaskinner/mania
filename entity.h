#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <SDL/SDL.h>
#include <stdint.h>
#include "coords.h"
#include "mania.h"

#define entity_draw(ent,st,surf) ({ \
        entity_t* __ent = (ent); \
        __ent->draw_f(__ent,(st),(surf)); })

#define entity_update(ent,st) ({ \
        entity_t* __ent = (ent); \
        __ent->update_f(__ent,(st)); })

typedef struct entity entity_t;

typedef void (*entity_draw_f)          (entity_t*,game_state_t*,SDL_Surface*);
typedef void (*entity_action_f)        (entity_t*,game_state_t*);

struct entity
{
    SDL_Rect         offset;
    SDL_Surface*     sprite;

    int              visible;

    entity_draw_f    draw_f;
    entity_action_f  update_f;
    entity_action_f  destruct_f;

    void*           entity_data;
    entity_action_f data_destruct_f;
};

void entity_init(entity_t* ent);

#endif
