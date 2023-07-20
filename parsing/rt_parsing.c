/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:39:57 by absaid            #+#    #+#             */
/*   Updated: 2023/07/20 21:26:44 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

void	objparse(t_data *data, char *line, int *i)
{
	char	**s;

	s = ft_split(line, " \t", 0);
	if (!s || !(*s) || **s == '#')
		return ;
	if (!ft_strncmp(s[0], "C", 1) && (ft_strlen(s[0]) == 1))
		return (parsecam(data, s), (*i)++, (void)0);
	else if ((!ft_strncmp(s[0], "A", 1) || !ft_strncmp(s[0], "L", 1)
			|| !ft_strncmp(s[0], "l", 1)) && (ft_strlen(s[0]) == 1))
		return (parselight(data, s), (*i)++, (void)0);
	else if (!ft_strncmp(s[0], "sp", 2) && (ft_strlen(s[0]) == 2))
		return (parsesp(data, s), (*i)++, (void)0);
	else if (!ft_strncmp(s[0], "cy", 2) && (ft_strlen(s[0]) == 2))
		return (parsecy(data, s), (*i)++, (void)0);
	else if (!ft_strncmp(s[0], "pl", 2) && (ft_strlen(s[0]) == 2))
		return (parsepl(data, s), (*i)++, (void)0);
	else
		ft_error("ERROR: Invalid Input rt.parsing.c", 1, 0);
	return ;
}

void	rt_parsing(t_data *data, int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		objparse(data, line, &i);
		free(line);
	}
	if (i == 0)
		ft_error("Error: Empty Map rt_parsing.c", 1, 0);
	return ;
}
