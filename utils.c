/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:21:06 by jpancorb          #+#    #+#             */
/*   Updated: 2024/04/04 21:31:39 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
		i++;
	write(fd, s, i);
}

double	ft_atof(const char *str)
{
	double	pow;
	int		sign;
	long	int_part;
	double	dbl_part;

	pow = 1;
	sign = 1;
	int_part = 0;
	dbl_part = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		int_part = (int_part * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	while (*str)
	{
		pow /= 10;
		dbl_part = dbl_part + (*str++ - 48) * pow;
	}
	return ((int_part + dbl_part) * sign);
}

void	malloc_error(void)
{
	perror("Malloc problems");
	exit(EXIT_FAILURE);
}
