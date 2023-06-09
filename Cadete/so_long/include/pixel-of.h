#ifndef PIXEL_OF_H
#define PIXEL_OF_H

#include <system-of.h>

typedef struct s_pixel t_pixel;
struct s_pixel{
    B8U r, g, b, a;
};

extern void pixel_rgba_set(t_pixel *set, B8U r, B8U g, B8U b, B8U a);
extern t_pixel pixel_rgba_local(B8U r, B8U g, B8U b, B8U a);

#endif // PIXEL_OF_H