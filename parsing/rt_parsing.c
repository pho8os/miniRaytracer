/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:39:57 by absaid            #+#    #+#             */
/*   Updated: 2023/05/30 11:24:32 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

t_scene *rt_parsing(int fd)
{
	char *line;
	t_scene *myscene;

	myscene = NULL;
	line = get_next_line(fd);
	while(line)
	{
		// addobj(&myscene, ft_newobj()
		line = get_next_line(fd);
	}
	return 0;
}