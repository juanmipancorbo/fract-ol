/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:45:44 by jpancorb          #+#    #+#             */
/*   Updated: 2024/03/28 21:50:45 by jpancorb         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                 COLOURS                                    */
/* ************************************************************************** */ 
#define BLACK       0x000000
#define RED         0xFF0000
#define GREEN       0x00FF00
#define YELLOW      0xFFFF00
#define BLUE        0x0000FF
#define MAGENTA     0xFF00FF
#define CYAN        0x00FFFF
#define WHITE       0xFFFFFF

#define MAGENTA         0xFF00FF
#define YELLOW          0xFFFF00
#define CYAN            0x00FFFF
#define ORANGE          0xFF4500
#define CHARTREUSE      0x7FFF00
#define DEEPPINK        0xFF1493
#define PURPLE          0x9400D3
#define LIMEGREEN       0x32CD32


/* ************************************************************************** */
/*                                 STRUCTS                                    */
/* ************************************************************************** */ 
typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
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
	double	scape_value;
	int		iterations_definition;
}				t_fractal;

/* ************************************************************************** */
/*                                 UTILS                                      */
/* ************************************************************************** */
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);

/* ************************************************************************** */
/*                               FUNCTIONS                                    */
/* ************************************************************************** */
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

/* ************************************************************************** */
/*                                 MATH                                       */
/* ************************************************************************** */
double		map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif