/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:39:57 by absaid            #+#    #+#             */
/*   Updated: 2023/06/05 01:08:46 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"



void	objparse(t_data *data, char *line)
{
	char **const s = ft_split(line, ' ');
	// puts(line);
	if(!ft_strncmp(s[0], "C", 1))
		return(parsecam(data, s), (void)0);
	if(!ft_strncmp(s[0], "A", 1) || !ft_strncmp(s[0], "L", 1))
		return(parselight(data, s), (void)0);
	if(!ft_strncmp(s[0], "sp", 2))
		return(parsesp(data, s), (void)0);
	if(!ft_strncmp(s[0], "cy", 2))
		return(parsecy(data, s), (void)0);
}

void	rt_parsing(t_data *data, int fd)
{
	char *line;
	
	line  = get_next_line(fd);
	while(line)
	{
		while(!*line)
			line = get_next_line(fd);
		objparse(data, line);
		line  = get_next_line(fd);
	}
}
