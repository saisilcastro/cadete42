#ifndef FLOOD_FILL_H
#define FLOOD_FILL_H

#define BUFFER_SIZE 0xFFFF

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern void file_get_size(const char *path, int *w, int *h);
extern char	**map_get(const char *path, int *w, int *h);
extern int flood_fill(const char *path);

#endif // FLOOD_FILL_H