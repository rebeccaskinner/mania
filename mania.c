#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <SDL/SDL.h>

#include "args.h"
#include "hash_utils.h"
#include "mania.h"

int main(int argc, char** argv)
{
    parse_flags(argc, argv);
    printf("...running game...\n");
    return 0;
}
