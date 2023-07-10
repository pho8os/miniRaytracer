/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:39:57 by absaid            #+#    #+#             */
/*   Updated: 2023/07/10 01:51:50 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

void	objparse(t_data *data, char *line, int *i)
{
	char **const s = ft_split(line, " \t", 0);
	if (!s || !(*s))
		return ;
	if(!ft_strncmp(s[0], "C", 1) && (ft_strlen(s[0]) == 1))
		return(parsecam(data, s), (*i)++, (void)0);
	else if ((!ft_strncmp(s[0], "A", 1) || !ft_strncmp(s[0], "L", 1) 
		|| !ft_strncmp(s[0], "l", 1)) && (ft_strlen(s[0]) == 1))
		return (parselight(data, s), (*i)++, (void)0);
	else if(!ft_strncmp(s[0], "sp", 2) && (ft_strlen(s[0]) == 2))
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
	char *line;
	int	i;

	line = NULL;
	i = 0;
	while(1)
	{
		line  = get_next_line(fd);
		if (!line)
			break ;
		objparse(data, line, &i);
		free(line);
	}
	if (i == 0)
		ft_error("Error: Empty Map rt_parsing.c", 1, 0);
	return ;
}


void printdata(t_data *data)
{
	if (data->cam){
		printf("C %f,%f,%f  %f,%f,%f    %d\n", data->cam->center.x, data->cam->center.y, data->cam->center.z, data->cam->forvec.x, data->cam->forvec.y, data->cam->forvec.z, data->cam->FOV);
		printf("C %f,%f,%f  %f,%f,%f    %d\n", data->cam->center.x, data->cam->center.y, data->cam->center.z, data->cam->sidevec.x, data->cam->sidevec.y, data->cam->sidevec.z, data->cam->FOV);
		printf("C %f,%f,%f  %f,%f,%f    %d\n", data->cam->center.x, data->cam->center.y, data->cam->center.z, data->cam->upvec.x, data->cam->upvec.y, data->cam->upvec.z, data->cam->FOV);
		
	}
	if (data->amlight)
		printf("A %f   %f,%f,%f\n", data->amlight->range, data->amlight->color.x, data->amlight->color.y, data->amlight->color.z);
	while (data->lights)
	{
		printf("L   %f,%f,%f     %f    %f,%f,%f\n", data->lights->pos.x, data->lights->pos.y, data->lights->pos.z, data->lights->range, data->lights->color.x, data->lights->color.y, data->lights->color.z);
		data->lights = data->lights->next;
	}
	while (data->cyl)
	{
		printf("cy   %f,%f,%f   %f,%f,%f  %f  %f  %f,%f,%f\n", data->cyl->center.x, data->cyl->center.y, data->cyl->center.z, data->cyl->nvec.x, data->cyl->nvec.y, data->cyl->nvec.z, data->cyl->diam, data->cyl->height, data->cyl->color.x, data->cyl->color.y, data->cyl->color.z);
		data->cyl = data->cyl->next;
	}
	while (data->pl)
	{
		printf("pl   %f,%f,%f   %f,%f,%f  %f,%f,%f\n", data->pl->point.x, data->pl->point.y, data->pl->point.z, data->pl->nvec.x, data->pl->nvec.y, data->pl->nvec.z, data->pl->color.x, data->pl->color.y, data->pl->color.z);
		data->pl = data->pl->next;
	}
	while (data->sph)
	{
		printf("sp   %f,%f,%f     %f    %f,%f,%f\n", data->sph->center.x, data->sph->center.y, data->sph->center.z, data->sph->diam, data->sph->color.x, data->sph->color.y, data->sph->color.z);
		data->sph = data->sph->next;
	}
}
