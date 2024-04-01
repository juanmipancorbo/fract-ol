/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:09:46 by jpancorb          #+#    #+#             */
/*   Updated: 2024/03/31 20:58:53 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
 
int	close_handler(t_fractal *fractal)
{
//	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
//	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS); 
}

/*	KeyPress prototype		*/
int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == ESC)
		close_handler(fractal);
	else if (keysym == LEFT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == RIGHT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == UP)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == DOWN)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == PLUS)
		fractal->iterations_definition += 10;
	else if (keysym == MINUS)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5)
		fractal->zoom *= 0.95; 
	else if (button == 4)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

/*	To change julia with mouse		*/
int	julia_mouse(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = map(x, -2, +2, WITH) * fractal->zoom + fractal->shift_x;
		fractal->julia_y = map(y, +2, -2, HEIGHT) * fractal->zoom + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}