/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:25:05 by absaid            #+#    #+#             */
/*   Updated: 2023/06/06 02:41:49 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <limits.h>

# ifndef ERROR_MSG
# define ERROR_MSG "ERROR: Incorect Input\n"
# endif // FOV_ERROR

static void	ft_error(char *error, int status, int opt)
{
	if (opt == 1)
		perror(error);
	if (opt == 0)
		write(2, error, ft_strlen(error));
	exit(status);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						n;
	unsigned long long int	check;
	int			result;

	if (!str) 
		ft_error(ERROR_MSG, 1, 0);
	i = 0;
	n = 1;
	result = 0;
	check = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ft_error(ERROR_MSG, 1, 0);
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		check = result * 10 + str[i] - '0';
		if (check > INT_MAX)
			ft_error("Error: Overflow in input: INT_MAX", 1, 0);
		result = check;
		i++;
	}
	if (str[i] != '\0')
		ft_error(ERROR_MSG, 1, 0);
	return ((int)result * n);
}
