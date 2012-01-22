#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>

#include "args.h"
#include "hash_utils.h"
#include "SDL_utils.h"
#include "entity.h"
#include "invader.h"
#include "utils.h"

#include "mania.h"

static game_state_t  gamestate;

static void init() __attribute__((constructor));

static void init()
{
    memset(&gamestate,0,sizeof(game_state_t));
}

static void gameloop(SDL_Surface* screen)
{
    SDL_Surface* bg = sdl_load_surface("resources/background.png");
    SDL_Event event;
    bool quit = 0;

    invader_t* invader = invader_new();

    while(SDL_PollEvent(&event) || !quit)
    {
        if(event.type == SDL_QUIT) quit=1;

        SDL_BlitSurface(bg,NULL,screen,NULL);

        invader_update(invader,&gamestate);
        invader_draw(invader,&gamestate,screen);

        SDL_Flip(screen);
        usleep(500);
    }

    SDL_FreeSurface(bg);
}

int main(int argc, char** argv)
{
    if(game_config_setup(&(gamestate.config),argc,argv))
    {
        printf("Error processing arguments\n");
        return 1;
    }
    SDL_Surface* screen = sdl_init_screen(gamestate.config.screen_width,
                                          gamestate.config.screen_height);
    gameloop(screen);
    SDL_Quit();
    return 0;
}
