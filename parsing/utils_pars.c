/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:57:10 by absaid            #+#    #+#             */
/*   Updated: 2023/06/06 22:06:06 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

void	ft_error(char *error, int status, int opt)
{
	if (opt == 1)
		perror(error);
	if (opt == 0)
		write(2, error, ft_strlen(error));
	exit(status);
}

double	ft_atod(char *s)
{
	double	res = 0.0;
	double	div = 1.0;
	int		sign = 1.0;


	if (!s)
		ft_error("Error: Invalid Input utils_pars.c\n", 1, 0);
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			sign *= -1.0;
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
	{
		res = (res * 10.0) + (*s - '0');
		s++;
		//check overflow
	}	
	if(*s == '.' && *(s + 1))
	{
		s++;
		while (*s && *s >= '0' && *s <= '9')
		{
			res = res + (*s - '0') / (10.0 * div);
			div = div * 10.0;
			s++;
		}
	}	
	if(*s)
		ft_error("Error: Invalid Input utils_pars.c\n", 1, 0);
	return (res * sign);
}
