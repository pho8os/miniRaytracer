/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:56:30 by absaid            #+#    #+#             */
/*   Updated: 2023/05/30 10:45:08 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"
# include "includes/rt_parser.h"

int	checkfile(char *file)
{
	int len;

	len = ft_strlen(file) - 3;
	if(ft_strncmp(file + len, ".rt", 3))
		return(-1);
	return(open(file, O_RDONLY));
}

int main(int ac, char **av)
{
	int fd;
	
	if(ac != 2)
		return(write(2, "Unvalid Args\n", 13), 1);	
	fd = checkfile(av[1]);
	if(fd < 0)
		return(write(2, "Unvalid file\n", 12), 1);	
	t_scene *scene;
	scene = rt_parsing(fd);
}