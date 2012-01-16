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

#include "mania.h"

static game_config_t config;
static game_state_t  gamestate;

static void init() __attribute__((constructor));

static void game_config_init()
{
    memset(&config,0,sizeof(game_config_t));
    config.screen_width  = 1024;
    config.screen_height = 768;
}

static void game_state_init()
{
    memset(&gamestate,0,sizeof(game_state_t));
}

static void init()
{
    game_config_init();
    game_state_init();
}

static void gameloop(SDL_Surface* screen)
{
    SDL_Surface* bg = sdl_load_surface("resources/background.png");
    SDL_Event event;
    bool quit = 0;

    while(!quit && SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            quit=1;
        }
        SDL_BlitSurface(bg,NULL,screen,NULL);
        SDL_Flip(screen);
        usleep(500);
    }

    SDL_FreeSurface(bg);
}

int main(int argc, char** argv)
{
    if(game_config_setup(&config,argc, argv))
    {
        printf("Error processing arguments\n");
        return 1;
    }
    SDL_Surface* screen = sdl_init_screen(config.screen_width,
                                         config.screen_height);
    gameloop(screen);
    SDL_Quit();
    return 0;
}
