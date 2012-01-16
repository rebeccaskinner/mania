#ifndef __MANIA_H__
#define __MANIA_H__
#include <stdint.h>
#include "list.h"

#define EXPECT(x,y) (__builtin_expect((x),(y)))
#define LIKELY(x)   (EXPECT((x),1))
#define UNLIKELY(x) (EXPECT((x),0))
#define UNUSED __attribute__((unused))

struct game_config
{
    uint16_t screen_height;
    uint16_t screen_width;
};

struct game_state
{
    int paused;
    linked_list_t* entities;
};

typedef struct game_config game_config_t;
typedef struct game_state game_state_t;

typedef unsigned char byte;
typedef int (*flag_fun)(game_config_t* config, const char* val);

#endif
