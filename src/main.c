/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:56:30 by absaid            #+#    #+#             */
/*   Updated: 2023/06/05 00:30:26 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
# include "../includes/rt_parser.h"

int	checkfile(char *file)
{
	int len;

	len = ft_strlen(file) - 3;
	if(ft_strncmp(file + len, ".rt", 3))
		return(-1);
	return(open(file, O_RDONLY));
}
void initdata(t_data *data)
{
	data->amlight = NULL;
	data->cam = NULL;
	data->cyl = NULL;
	data->sph = NULL;
	data->lights = NULL;
	//initilize mlx params;
}
void printdata(t_data *data)
{
	printf("C %f,%f,%f  %f,%f,%f    %d\n", data->cam->center.x, data->cam->center.y,  data->cam->center.z , data->cam->nvec.x, data->cam->nvec.y, data->cam->nvec.z, data->cam->FOV);
	printf("A %f   %d\n", data->amlight->range, data->amlight->color);
	while(data->cyl)
	{
		printf("cy   %f,%f,%f   %f,%f,%f  %f  %f  %d\n", data->cyl->center.x, data->cyl->center.y, data->cyl->center.z, data->cyl->nvec.x, data->cyl->nvec.y, data->cyl->nvec.z,data->cyl->diam ,data->cyl->height , data->cyl->color);
		data->cyl = data->cyl->next;
	}
	while(data->sph)
	{
		printf("sp   %f,%f,%f     %f    %d\n", data->sph->center.x, data->sph->center.y, data->sph->center.z ,data->sph->diam , data->sph->color);
		data->sph = data->sph->next;
	}
	while(data->lights)
	{
		printf("HEY\n");
		printf("L   %f,%f,%f     %f    %d\n", data->lights->pos.x, data->lights->pos.y, data->lights->pos.z, data->lights->range , data->lights->color);
		data->lights = data->lights->next;
	}
	
}
int main(int ac, char **av)
{
	int fd;
	t_data data;

	if(ac != 2)
		return(write(2, "Unvalid Args\n", 13), 1);	
	fd = checkfile(av[1]);
	if(fd < 0)
		return(write(2, "Unvalid file\n", 12), 1);
	initdata(&data);
	rt_parsing(&data, fd);
	printdata(&data);
	// init_mlx();
	// render(data);
}