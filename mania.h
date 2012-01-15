#ifndef __MANIA_H__
#define __MANIA_H__

#define EXPECT(x,y) (__builtin_expect((x),(y)))
#define LIKELY(x)   (EXPECT((x),1))
#define UNLIKELY(x) (EXPECT((x),0))
#define UNUSED __attribute__((unused))

struct game_config
{
    int run_game;
};

typedef struct game_config game_config_t;
typedef unsigned char byte;
typedef int (*flag_fun)(game_config_t* config, const char* val);

#endif
