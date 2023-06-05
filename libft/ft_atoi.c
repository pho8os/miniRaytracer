/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:25:05 by absaid            #+#    #+#             */
/*   Updated: 2023/06/05 01:14:39 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *str)
{
	int						i;
	int						n;
	unsigned long long int	result;

	i = 0;
	n = 1;
	result = 0;
	// puts(str);
	(!str) && (puts("error1"), exit(1), 0);
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		(str[i] == '-') && (n *= -1);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
		if (result > 9223372036854775807 && n == -1)
			return (puts("error"), exit(1), 0);
		if (result > 9223372036854775807)
			return (puts("error"), exit(1), 0);
	}
	// (str[i]) && (puts("error2"), exit(1), 0);
	return ((int)result * n);
}
