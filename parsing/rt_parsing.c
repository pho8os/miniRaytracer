/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:39:57 by absaid            #+#    #+#             */
/*   Updated: 2023/06/06 09:37:57 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

void	objparse(t_data *data, char *line)
{
	// TODO : There are some maps that have an xpm file for texture
	// TODO :  Check_if_range_is_respected_else_return_error() funtion
	// TODO :  Check_if_range_is_respected_else_return_error() funtion
	// TODO : 'l', 'p', 'tx'...
	// TODO : Handle problem of parsing 255,,,,,255,255
	char **const s = ft_split(line, ' ');

	if (!s || !(*s))
		return ;
	if(!ft_strncmp(s[0], "C", 1) && (ft_strlen(s[0]) == 1))
		return(parsecam(data, s), (void)0);
	else if ((!ft_strncmp(s[0], "A", 1) || !ft_strncmp(s[0], "L", 1) 
		|| !ft_strncmp(s[0], "l", 1)) && (ft_strlen(s[0]) == 1))
		return(parselight(data, s), (void)0);
	else if(!ft_strncmp(s[0], "sp", 2) && (ft_strlen(s[0]) == 2))
		return(parsesp(data, s), (void)0);
	else if (!ft_strncmp(s[0], "cy", 2) && (ft_strlen(s[0]) == 2))
		return(parsecy(data, s), (void)0);
	// TODO : plane
	else if (!ft_strncmp(s[0], "pl", 2) && (ft_strlen(s[0]) == 2))
		return ;
	else
		ft_error("ERROR: Invalid Input rt.parsing.c", 1, 0);
	return ;
}

void	rt_parsing(t_data *data, int fd)
{
	char *line;
	int	i;

	line = NULL;
	i = 0;
	// TODO: Freeing the pointer in the inner while??
	while(1)
	{
		line  = get_next_line(fd);
		if (!line)
			break ;
		while (!*line)
			line = get_next_line(fd);
		objparse(data, line);
		free(line);
		i++;
	}
	return ;
}
