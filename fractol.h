/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:45:44 by jpancorb          #+#    #+#             */
/*   Updated: 2024/03/26 20:32:11 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //printf for debugging
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

#define	WITH	800
#define HEIGHT	800

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel; 
	int		line_len;
	int		endian;
}				t_img;


typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}				t_fractal;

// *** utils ***

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif