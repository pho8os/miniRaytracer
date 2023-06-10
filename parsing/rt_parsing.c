/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:39:57 by absaid            #+#    #+#             */
/*   Updated: 2023/06/07 05:01:16 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

void	objparse(t_data *data, char *line)
{
	char **const s = ft_split(line, " \t", 0);

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
	else if (!ft_strncmp(s[0], "pl", 2) && (ft_strlen(s[0]) == 2))
		return (parsepl(data, s), (void)0);
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


void printdata(t_data *data)
{
	if (data->cam)
		printf("C %f,%f,%f  %f,%f,%f    %d\n", data->cam->center.x, data->cam->center.y, data->cam->center.z, data->cam->nvec.x, data->cam->nvec.y, data->cam->nvec.z, data->cam->FOV);
	if (data->amlight)
		printf("A %f   %d\n", data->amlight->range, data->amlight->color);
	while (data->lights)
	{
		// printf("HEY\n");
		printf("L   %f,%f,%f     %f    %d\n", data->lights->pos.x, data->lights->pos.y, data->lights->pos.z, data->lights->range, data->lights->color);
		data->lights = data->lights->next;
	}
	while (data->cyl)
	{
		printf("cy   %f,%f,%f   %f,%f,%f  %f  %f  %d\n", data->cyl->center.x, data->cyl->center.y, data->cyl->center.z, data->cyl->nvec.x, data->cyl->nvec.y, data->cyl->nvec.z, data->cyl->diam, data->cyl->height, data->cyl->color);
		data->cyl = data->cyl->next;
	}
	while (data->pl)
	{
		printf("pl   %f,%f,%f   %f,%f,%f  %d\n", data->pl->point.x, data->pl->point.y, data->pl->point.z, data->pl->nvec.x, data->pl->nvec.y, data->pl->nvec.z, data->pl->color);
		data->pl = data->pl->next;
	}
	while (data->sph)
	{
		printf("sp   %f,%f,%f     %f    %d\n", data->sph->center.x, data->sph->center.y, data->sph->center.z, data->sph->diam, data->sph->color);
		data->sph = data->sph->next;
	}
}
