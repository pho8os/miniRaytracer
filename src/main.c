/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:56:30 by absaid            #+#    #+#             */
/*   Updated: 2023/06/03 13:26:32 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/*
	• Allowed functions :
		open, close, read, write,
		printf, malloc, free, perror,
		strerror, exit
	• All functions of the math library (-lm man man 3 math)
	• All functions of the MinilibX
*/

// *	Check file name syntax. does it finish with ".rt"?
int	checkfile_name(char *file)
{
	int	len;

	len = ft_strlen(file) - 3;
	if(ft_strncmp(file + len, ".rt", 3))
		return(-1);
	return(open(file, O_RDONLY));
}

// *	Initialize data struct
void	init_data(t_data *data, t_scene *scene)
{
	data->fd = 0;
	data->scene = scene;
	data->scene->cylinders = NULL;
	data->scene->spheres = NULL;
	return ;
}

int main(int ac, char **av)
{
	t_data	data;
	t_scene	scene;

	if(ac != 2)
		return(write(2, "Invalid Arguments\n", 19), 1);
	init_data(&data, &scene);
	data.fd = checkfile_name(av[1]);
	if(data.fd < 0)
		return(write(2, "Invalid File\n", 14), 1);
	parse_file_and_initialize_scene(&data);

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
	return (0);
}
