/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:04:36 by jpancorb          #+#    #+#             */
/*   Updated: 2024/04/04 21:32:54 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->scape_value = 4;
	fractal->iterations_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	data_init_bonus(t_fractal *fractal)
{
	fractal->scape_value = 4;
	fractal->iterations_definition = 102;
	fractal->shift_x = -1.761233;
	fractal->shift_y = 0.021584;
	fractal->zoom = 0.037404;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 02, (1L << 0), key_handler, fractal);
	mlx_hook(fractal->mlx_window, 04, (1L << 2), mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, 17, (1L << 17), close_handler, fractal);
	mlx_hook(fractal->mlx_window, 06, (1L << 6), julia_mouse, fractal);
}

static void	mandatory_or_bonus(t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "burning_ship", 12))
		data_init_bonus(fractal);
	else
		data_init(fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_len,
			&fractal->img.endian);
	events_init(fractal);
	mandatory_or_bonus(fractal);
}
