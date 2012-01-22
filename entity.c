#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "utils.h"
#include "mania.h"
#include "entity.h"

void entity_draw_def(entity_t* ent, game_state_t* st, SDL_Surface* surf)
{
    if(!ent->visible || !ent->sprite) return;
    SDL_BlitSurface(ent->sprite, NULL, surf, &(ent->offset));
    return;
}

void entity_update_def(entity_t* ent, game_state_t* st)
{
    return;
}

entity_t* entity_new()
{
    entity_t* ent = malloc0(sizeof(entity_t));
    ent->draw_f = entity_draw_def;
    ent->update_f = entity_update_def;
    return ent;
}
