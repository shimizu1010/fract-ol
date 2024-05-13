/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:07:37 by nshahid           #+#    #+#             */
/*   Updated: 2024/05/07 18:54:13 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 500
#define MAX_ITER 100
#define ESC_KEY 53

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*data_addr;
	int		bpp;
	int		line_size;
	int		endian;
	int		x;
	int		y;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	double	c_re;
	double	c_im;
	char	*type;
}			t_fractal;