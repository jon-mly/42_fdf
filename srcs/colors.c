#include "fdf.h"

int     get_endian_color(unsigned int r, unsigned int g, unsigned int b)
{
    int     endian_color;

    endian_color = 0;
    endian_color = ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF);
    return (endian_color);
}
