#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "args.h"
#include "hash_utils.h"
#include "mania.h"

static game_config_t config;

static void set_default_options() __attribute__((constructor));

void set_default_options()
{
    config.screen_width  = 1024;
    config.screen_height = 768;
}

int main(int argc, char** argv)
{
    if(game_config_setup(&config,argc, argv))
    {
        printf("Error processing arguments\n");
        return 1;
    }

    SDL_Surface* bg = NULL;
    SDL_Surface* screen = NULL;


    SDL_Init(SDL_INIT_EVERYTHING);

    screen = SDL_SetVideoMode(config.screen_width,
                              config.screen_height,
                              32,
                              SDL_SWSURFACE);

    bg = IMG_Load("resources/background.png");
    SDL_BlitSurface(bg,NULL,screen,NULL);
    SDL_Flip(screen);
    SDL_Delay(2000);
    SDL_FreeSurface(bg);
    SDL_Quit();

    return 0;
}
