/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:37:18 by jpancorb          #+#    #+#             */
/*   Updated: 2024/04/04 21:33:00 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_error_text(int fd)
{
	ft_putstr_fd("Please enter: \n", fd);
	ft_putstr_fd("\t\"./fractol mandelbrot\" or \n", fd);
	ft_putstr_fd("\t\"./fractol julia <value_1> <value_2>\" or\n", fd);
	ft_putstr_fd("\t\"./fractol julia_mouse\" or\n", fd);
	ft_putstr_fd("\t\"./fractol burning_ship\"\n", fd);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		|| (argc == 2 && !ft_strncmp(argv[1], "julia_mouse", 11))
		|| (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12)))
	{
		fractal.name = argv[1];
		if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		{
			fractal.julia_x = atof(argv[2]);
			fractal.julia_y = atof(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		put_error_text(STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
