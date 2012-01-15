#ifndef __MANIA_H__
#define __MANIA_H__
#include <stdint.h>

#define EXPECT(x,y) (__builtin_expect((x),(y)))
#define LIKELY(x)   (EXPECT((x),1))
#define UNLIKELY(x) (EXPECT((x),0))
#define UNUSED __attribute__((unused))

struct game_config
{
    uint16_t screen_height;
    uint16_t screen_width;
};

typedef struct game_config game_config_t;
typedef unsigned char byte;
typedef int (*flag_fun)(game_config_t* config, const char* val);

#endif
