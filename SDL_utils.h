#ifndef __SDL_UTILS_H__
#define __SDL_UTILS_H__
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdint.h>

SDL_Surface* sdl_load_surface(const char* res_path);
SDL_Surface* sdl_init_screen(uint16_t w, uint16_t h);

#endif
