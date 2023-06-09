#ifndef MATH_OF_H
#define MATH_OF_H

#include <system-of.h>

typedef struct s_vi2d t_vi2d;
struct s_vi2d{
    B32 x;
    B32 y;  
};

extern t_vi2d   vi2d_start(B32 x, B32 y);

typedef struct s_vf2d t_vf2d;
struct s_vf2d{
    BP32 x;
    BP32 y;
};

extern t_vf2d   vf2d_start(BP32 x, BP32 y);

#endif // MATH_OF_H