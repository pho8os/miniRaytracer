/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:39:57 by absaid            #+#    #+#             */
/*   Updated: 2023/06/02 21:09:49 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"



t_object	*objparse(char *line, int fd)
{
	char **const s = ft_split(line, ' ');
	if (!line)
		return (NULL);
	if(ft_strncmp(s[0], "sp", 2))
		return(parsesph(s));
	if(ft_strncmp(s[0], "cy", 2))
		return(parsecyl(s));
	return(NULL);
}

t_object *rt_parsing(int fd)
{
	int i[3];

	char *line;
	
	line  = get_next_line(fd);
	while(!*line)
		line = get_next_line(fd);
	t_object *const	obj = objparse(get_next_line(fd), fd);
	
	return (obj);
}