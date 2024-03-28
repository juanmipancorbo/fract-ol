/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:53:35 by jpancorb          #+#    #+#             */
/*   Updated: 2024/03/28 21:58:33 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;  
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	i = 0;
	z.x = 0.0;
	z.y = 0.0; 

	c.x = map(x, -2, +2, WITH);
	c.y = map(y, +2, -2, HEIGHT); 

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