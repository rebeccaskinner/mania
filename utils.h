#ifndef __UTILS_H__
#define __UTILS_H__

#define EXPECT(x,y) (__builtin_expect((x),(y)))
#define LIKELY(x)   (EXPECT((x),1))
#define UNLIKELY(x) (EXPECT((x),0))
#define UNUSED __attribute__((unused))

#define malloc0(s) ({ size_t __m0_s = (s); \
                      void* __m0_p = malloc(__m0_s); \
                      memset(__m0_p,0,__m0_s); \
                      __m0_p; })

#define free0(p) ({ free(p); p = NULL; p; })

#endif
