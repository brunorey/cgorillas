#ifndef __cgorillas_aux__
#define __cgorillas_aux__ 1

#include <graphics.h>

float myrand(int min, int max)
{
    return min + (((rand()+0.0)/(RAND_MAX+0.0))*(max-min));
}

#endif