/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:53:35 by jpancorb          #+#    #+#             */
/*   Updated: 2024/04/03 21:24:48 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;  
}

static void	fractal_type(t_complex *z, t_complex *c, t_fractal *fractal)
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

static void	handle_pixel_mandatory(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	i = 0;
	z.x = (map(x, -2, +2, WITH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	fractal_type(&z, &c, fractal);
	while (i < fractal->iterations_definition) 
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > __DBL_MAX__)
		{
			colour = map(i, WHITE, BLACK, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, colour);
			return ; 
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, BSSCOLOUR);
}
static void	handle_pixel_bonus(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	i = 0;
	z.x = (map(x, -2, +2, WITH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, -2, +2, HEIGHT) * fractal->zoom) - fractal->shift_y;
	fractal_type(&z, &c, fractal);
	while (i < fractal->iterations_definition) 
	{
		z = sum_complex(square_complex(z), c);
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		if ((z.x * z.x) + (z.y * z.y) > __DBL_MAX__)
		{
			colour = map(i, WHITE, BLACK, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, colour);
			return ; 
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, BSSCOLOUR);
}

void	fractal_render(t_fractal *fractal)
{
	 int	x;
	 int	y;

	 y = -1;
	 while (++y < HEIGHT)
	 {
		x = -1;
		if (!ft_strncmp(fractal->name, "burning_ship", 12))
			while (++x < WITH)
				handle_pixel_bonus(x, y, fractal);
		else
			while (++x < WITH)
				handle_pixel_mandatory(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, 
	 											fractal->img.img_ptr, 0, 0);
}