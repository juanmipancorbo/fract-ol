/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:04:36 by jpancorb          #+#    #+#             */
/*   Updated: 2024/03/26 21:57:58 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error(); // TO DO
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, 
											WITH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_image//what? no lo encuentro
	}
}