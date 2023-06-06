/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:57:10 by absaid            #+#    #+#             */
/*   Updated: 2023/06/06 08:48:35 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

double	ft_atod(char *s)
{
	double	res = 0.0;
	double	div = 1.0;
	int		sign = 1.0;
	int		deci = 0;
	
	if (!s)
		ft_error("Error: Invalid Input utils_pars.c\n", 1, 0);
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			sign *= -1.0;
		s++;
	}
	while (*s)
	{	
		if ((*s >= '0' && *s <= '9') && deci == 0)
			res = (res * 10.0) + (*s - '0');
		else if ((*s >= '0' && *s <= '9') && deci == 1)
		{
			res = res + (*s - '0') / (10.0 * div);
			div = div * 10.0;
		}
		else if (*s == '.')
		{	
			deci = 1;
			s++;
		}
		
		else
			ft_error("Error: Invalid Input utils_pars.c\n", 1, 0);
		(!ft_isdigit(*s)) && (ft_error("Error: Invalid Input 33 utils_pars.c\n", 1, 0), 0);
		s++;
	}
	return (res * sign);
}
