/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:53:35 by jpancorb          #+#    #+#             */
/*   Updated: 2024/04/02 23:10:45 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;  
}

static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	} 
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	i = 0;
	//z.x = (map(x, -2, +2, WITH) * fractal->zoom) + fractal->shift_x;
	z.x = ((+2.0 - -2.0) * x / WITH + -2.0) * fractal->zoom + fractal->shift_x;
	//z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	z.y = ((-2.0 - +2.0) * y / HEIGHT + +2.0) * fractal->zoom + fractal->shift_y;
	mandel_or_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition) 
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->scape_value)
		{
			colour = map(i, BLACK, WHITE, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, colour);
			return ; 
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	 int	x;
	 int	y;

	 y = -1;
	 while (++y < HEIGHT)
	 {
		x = -1;
		while (++x < WITH)
		{
			handle_pixel(x, y, fractal);
		}
	 }
	 mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, 
	 											fractal->img.img_ptr, 0, 0);
}