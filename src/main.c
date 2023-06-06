/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:56:30 by absaid            #+#    #+#             */
/*   Updated: 2023/06/06 00:00:45 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/rt_parser.h"

/*
	• Allowed functions :
		open, close, read, write,
		printf, malloc, free, perror,
		strerror, exit
	• All functions of the math library (-lm man man 3 math)
	• All functions of the MinilibX
*/

int checkfile(char *file)
{
	int len;

	len = ft_strlen(file) - 3;
	if (ft_strncmp(file + len, ".rt", 3))
		return (-1);
	return (open(file, O_RDONLY));
}

// Initilizes mlx params;
void initdata(t_data *data)
{
	data->amlight = NULL;
	data->cam = NULL;
	data->cyl = NULL;
	data->sph = NULL;
	data->lights = NULL;
}

void printdata(t_data *data)
{
	if (data->cam)
		printf("C %f,%f,%f  %f,%f,%f    %d\n", data->cam->center.x, data->cam->center.y, data->cam->center.z, data->cam->nvec.x, data->cam->nvec.y, data->cam->nvec.z, data->cam->FOV);
	if (data->amlight)
		printf("A %f   %d\n", data->amlight->range, data->amlight->color);
	while (data->cyl)
	{
		printf("cy   %f,%f,%f   %f,%f,%f  %f  %f  %d\n", data->cyl->center.x, data->cyl->center.y, data->cyl->center.z, data->cyl->nvec.x, data->cyl->nvec.y, data->cyl->nvec.z, data->cyl->diam, data->cyl->height, data->cyl->color);
		data->cyl = data->cyl->next;
	}
	while (data->sph)
	{
		printf("sp   %f,%f,%f     %f    %d\n", data->sph->center.x, data->sph->center.y, data->sph->center.z, data->sph->diam, data->sph->color);
		data->sph = data->sph->next;
	}
	while (data->lights)
	{
		printf("HEY\n");
		printf("L   %f,%f,%f     %f    %d\n", data->lights->pos.x, data->lights->pos.y, data->lights->pos.z, data->lights->range, data->lights->color);
		data->lights = data->lights->next;
	}
}
int main(int ac, char **av)
{
	int fd;
	t_data data;

	if (ac != 2)
		ft_error("Invalid Arguments", 1, 0);
	fd = checkfile(av[1]);
	if (fd < 0)
		ft_error("Invalid File", 1, 0);
	initdata(&data);
	rt_parsing(&data, fd);
	printdata(&data);
	// init_mlx();
	// render(data);
	
	// TODO: Thinking about rest of the implementation...
	//	-----------------------------------------------------

	//	Making the connection with the graphical system (AKA: MiniLibx)
	// Create an image (MiniLibx)
	//	Draw_in_an_image();
	// ...
	// ...
	// ...
	// keybord_hooks() :
	// ESC key,
	// red cross on the window's frame must close the window
	// close(data.fd);
	// If something has to be freed, it should be freed
}
