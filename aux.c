#ifndef __cgorillas_aux__
#define __cgorillas_aux__ 1

#include "aux.h"
#include <graphics.h>

float myrand(float min, float max)
{
    return min + (((rand()+0.0)/(RAND_MAX+0.0))*(max-min));
}

#endif
