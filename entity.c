#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "utils.h"
#include "mania.h"
#include "entity.h"

static void entity_draw_def(entity_t* ent, game_state_t* st, SDL_Surface* surf)
{
    if(!ent->visible || !ent->sprite)
    {
        printf("entity_draw_def: not visible or no sprite\n");
        return;
    }
    SDL_BlitSurface(ent->sprite, NULL, surf, &(ent->offset));
    return;
}

static void entity_update_def(entity_t* ent, game_state_t* st)
{
    return;
}

void entity_init(entity_t* ent)
{
    ent->draw_f = entity_draw_def;
    ent->update_f = entity_update_def;
}

