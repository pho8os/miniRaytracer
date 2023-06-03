/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:39:57 by absaid            #+#    #+#             */
/*   Updated: 2023/06/03 13:21:08 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

// *	Return type of the object
int	object_type(char *first_keyword)
{
	// TODO : Freeing double pointer `s` before each return()
	char **const s = ft_split(first_keyword, ' ');
	if (!first_keyword)
		return (ERROR);
	if(ft_strncmp(s[0], "sp", 2))
		return(SPHERE);
	if(ft_strncmp(s[0], "cy", 2))
		return(CYLINDER);
	return(ERROR);
}


// init_node_of_camera(line)
// {
// 	...
// }

// init_node_of_ambient_light(line)
// {
// 	...
// }

// init_node_of_camera(line)
// {
// 	...
// }

// init_node_of_light(line)
// {
// 	...
// }

// //void	init_node_of_sphere(line)
// {
 		// TODO: Don't forget to handle error
 		/*
 		*	identifier: sp
 		∗	x,y,z coordinates of the sphere center: 0.0,0.0,20.6
 		∗	the sphere diameter: 12.6
 		∗	R,G,B colors in range [0-255]: 10, 0, 255
 		*/

// 	return ;
// }

// init_node_of_cylinder(line)
// {
	// TODO: Don't forget to handle error
	/*
	∗	identifier: cy
	∗	x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
	∗	3d normalized vector of axis of cylinder. In range [-1,1]
			for each x,y,z axis: 0.0,0.0,1.0
	∗	the cylinder diameter: 14.2
	∗	the cylinder height: 21.42
	∗	R,G,B colors in range [0,255]: 10, 0, 255
	*/
	
	// return ;
// }

// *	Check for errors in the given file.rt parameter and initialize scene
void	parse_file_and_initialize_scene(t_data *data)
{
	(void)data;

	// char	*line;
	// char	*splited_line;

	// line = NULL;
	// while (line)
	// {
	// 	line = get_next_line(data->fd);
	// 	splited_line = ft_split(line, ' ');
	// 	if (!splited_line)
	// 		print_error_and_exit("Parsing Error", NULL, 2);
	// 	if (object_type(splited_line[0]) == SPHERE)
	// 	{
	// 		// init_node_of_sphere(line);
	// 		// data->scene->spheres = data->scene->spheres->next; // use t_sphere *tmp
	// 	}
	// 	if (object_type(splited_line[0]) == CYLINDER)
	// 	{
	// 		// init_node_of_cylinder(line);
	// 		// data->scene->cylinder = data->scene->cylinder->next; // use t_cylinder *tmp
	// 	}
	// 	if (object_type(splited_line[0]) == PLANE)
	// 	{
	// 		// init_node_of_plane(line);
	// 		// data->scene->plane = data->scene->plane->next; // use t_plane *tmp
	// 	}
	// 	if (object_type(splited_line[0]) == CAMERA)
	// 	{
	// 		// init_node_of_camera(line);
	// 		// data->scene->camera = data->scene->camera->next; // use t_camera *tmp
	// 	}
	// 	if (object_type(splited_line[0]) == AMBIENT_LIGHT)
	// 	{
	// 		// init_node_of_camera(line);
	// 		// data->scene->camera = data->scene->camera->next; // use t_camera *tmp
	// 	}
	// 	if (object_type(splited_line[0]) == LIGHT)
	// 	{
	// 		// init_node_of_LIGHT(line);
	// 		// data->scene->LIGHT = data->scene->LIGHT->next; // use t_LIGHT *tmp
	// 	}
	// 	free_pointers(splited_line);
	//	free(line);
	// }
	return ;
}
