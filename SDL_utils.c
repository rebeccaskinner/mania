#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

static void sdl_init() __attribute__((constructor));

static void sdl_init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

SDL_Surface* sdl_load_surface(const char* res_path)
{
    SDL_Surface* tmp = IMG_Load(res_path);
    SDL_Surface* opt = NULL;

    if(!tmp) return NULL;

    opt = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);

    return opt;
}

SDL_Surface* sdl_init_screen(uint16_t w, uint16_t h)
{
    return SDL_SetVideoMode(w,h,32,SDL_SWSURFACE);
}
