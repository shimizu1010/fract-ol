/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by nshahid           #+#    #+#             */
/*   Updated: 2024/05/07 21:57:35 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_color_to_pixel(t_fractal *f, int x, int y, int color)
{
	int	i;

	i = (x * f->bpp / 8) + (y * f->line_size);
	if (x >= 0 && x < SIZE && y >= 0 && y < SIZE)
	{
		f->data_addr[i] = color;
		f->data_addr[++i] = color >> 8;
		f->data_addr[++i] = color >> 16;
	}
}

static void	calculate_fractal(t_fractal *f)
{
	int		iteration;
	double	cx;
	double	cy;
	int		color;
	double	zx;
	double	zy;
	double	x_temp;

	iteration = 0;
	cx = f->x / f->zoom + f->offset_x;
	cy = f->y / f->zoom + f->offset_y;
	if (strcmp(f->type, "julia") == 0)
	{
		zx = 1.5 * (f->x - SIZE / 2) / (0.5 * f->zoom * SIZE) + f->c_re;
		zy = (f->y - SIZE / 2) / (0.5 * f->zoom * SIZE) + f->c_im;
	}
	else
	{
		zx = 0;
		zy = 0;
	}
	while (iteration < f->max_iter && (zx * zx + zy * zy) < 4)
	{
		x_temp = zx * zx - zy * zy;
		zy = 2 * zx * zy + cy;
		zx = x_temp + cx;
		iteration++;
	}
	if (iteration == f->max_iter)
		color = 0x000000;
	else
		color = iteration * 0x120B09;
	put_color_to_pixel(f, f->x, f->y, color);
}

static void	draw_fractal(t_fractal *f)
{
	f->x = 0;
	while (f->x < SIZE)
	{
		f->y = 0;
		while (f->y < SIZE)
		{
			calculate_fractal(f);
			f->y++;
		}
		f->x++;
	}
}

static int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(f->mlx, f->window);
		exit(0);
	}
	return (0);
}

static int	mouse_hook(int button, int x, int y, t_fractal *f)
{
	if (button == 4)
	{
		f->zoom *= 1.1;
	}
	else if (button == 5)
	{
		f->zoom *= 0.9;
	}
	draw_fractal(f);
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	return (0);
}

static int	close_hook(t_fractal *f)
{
	mlx_destroy_window(f->mlx, f->window);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal f;

	if (argc < 2 || (strcmp(argv[1], "mandelbrot") && strcmp(argv[1], "julia")))
	{
		printf("Usage: %s [mandelbrot | julia]\n", argv[0]);
		return (1);
	}
	f.mlx = mlx_init();
	f.window = mlx_new_window(f.mlx, SIZE, SIZE, "Fractal Viewer");
	f.image = mlx_new_image(f.mlx, SIZE, SIZE);
	f.data_addr = mlx_get_data_addr(f.image, &f.bpp, &f.line_size, &f.endian);
	f.zoom = 200;
	f.offset_x = -2.0;
	f.offset_y = -1.5;
	f.max_iter = MAX_ITER;
	f.type = argv[1];
	f.c_re = (argc > 2) ? atof(argv[2]) : -0.7;
	f.c_im = (argc > 3) ? atof(argv[3]) : 0.27015;
	draw_fractal(&f);
	mlx_put_image_to_window(f.mlx, f.window, f.image, 0, 0);
	mlx_key_hook(f.window, key_hook, &f);
	mlx_mouse_hook(f.window, mouse_hook, &f);
	mlx_hook(f.window, 17, 0L, close_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}