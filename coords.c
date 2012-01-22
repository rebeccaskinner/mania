#include <math.h>
#include <stdlib.h>
#include "coords.h"

point_t vector_to_offset(vector_t* v)
{
    point_t p = {0,0};
    if(!v) return p;
    p.x = v->magnitude*sinf(v->theta);
    p.y = v->magnitude*cosf(v->theta);

    return p;
}
