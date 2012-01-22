#ifndef __COORDS_H__
#define __COORDS_H__
#include <stdint.h>

struct point;
struct vector;
struct quadtree;

typedef struct point point_t;
typedef struct vector vector_t;
typedef struct quadtree quadtree_t;

struct point
{
    uint16_t x; // in pixels
    uint16_t y; // in pixels
};

struct vector
{
    float theta;     // store the direction in radians
    float magnitude; // store the magnitude in pixels
};

point_t vector_to_offset(vector_t* v);

/*
 * Partition space into quadrants
 *
 * +----+----+
 * | Q2 | Q1 |
 * +----+----+
 * | Q3 | Q4 |
 * +----+----+
 */
struct quadtree
{
    point_t     center;
    quadtree_t* quadrants[4];
};

#endif
