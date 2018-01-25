#include "fdf.h"
#include <unistd.h>
#include <stdlib.h>

void    set_line_draw(t_view view)
{
    t_point     start;
    t_point     end;

    start.x = 100;
    start.y = 100;
    end.x = 1100;
    end.y = 100;
    draw_line(start, end, view);
    start.x = 200;
    start.y = 100;
    end.x = 200;
    end.y = 700;
    draw_line(start, end, view);
    start.x = 250;
    start.y = 400;
    end.x = 1000;
    end.y = 700;
    draw_line(start, end, view);
}

void    draw_in_image(void *image, t_view view)
{
    int x;
    int y;

    y = -1;
    while (++y < 300)
    {
        x = -1;
        while (++x < 300)
            mlx_pixel_put(view.mlx_ptr, image, x, y, get_endian_color(255, 255, 255));
    }
}
int     deal_key(int key, void *param)
{
    if (key == 53)
        exit(0);
    return (0);
}

int     main(void)
{
    t_view  view;
    void    *image;

    view.mlx_ptr = mlx_init();
    view.win_ptr = mlx_new_window(view.mlx_ptr, 1200, 800, "mlx 42");
    image = mlx_new_image(view.mlx_ptr, 300, 300);
    draw_in_image(image, view);
    mlx_put_image_to_window(view.mlx_ptr, view.win_ptr, image, 0, 0);
    mlx_key_hook(view.win_ptr, deal_key, (void *)&view);
    mlx_loop(view.mlx_ptr);
}
