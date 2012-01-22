#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "utils.h"
#include "mania.h"
#include "entity.h"
#include "coords.h"

#include "invader.h"

#define INVADER_PATH "resources/invader.png"

SDL_Surface* sprite_ref;

static void init() __attribute__((constructor));

static void init()
{
    sprite_ref = IMG_Load(INVADER_PATH);
}

void invader_update_f(entity_t* e, game_state_t* st)
{
    invader_t* inv = (invader_t*)e;
    inv->entity.offset.x++;
    inv->entity.offset.y++;
} 

invader_t* invader_new()
{
    uint32_t color_key;
    invader_t* invader = malloc0(sizeof(invader_t));
    entity_init((entity_t*)invader);
    invader->entity.visible = 1;
    invader->entity.sprite = SDL_DisplayFormat(sprite_ref);
    color_key = SDL_MapRGB(invader->entity.sprite->format,0xff,0,0xff);
    SDL_SetColorKey(invader->entity.sprite,SDL_SRCCOLORKEY,color_key);
    invader->entity.update_f = invader_update_f;
    return invader;
}
