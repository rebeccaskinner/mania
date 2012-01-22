#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <SDL/SDL.h>
#include <stdint.h>
#include "coords.h"
#include "mania.h"

typedef struct entity entity_t;

typedef void (*entity_draw_f)  (entity_t*,game_state_t*,SDL_Surface*);
typedef void (*entity_update_f)(entity_t*,game_state_t*);

struct entity
{
    SDL_Rect        offset;
    int             visible;
    SDL_Surface*    sprite;
    entity_draw_f   draw_f;
    entity_update_f update_f;
    void*           entity_data;
};

#endif
