/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:58:50 by absaid            #+#    #+#             */
/*   Updated: 2023/06/03 13:29:26 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

# include "../libft/libft.h"
# include "../libgc/gc.h"
# include "../includes/rt_parser.h"
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/* ************************************************************************** */
/*									DATA									  */
/* ************************************************************************** */

// *	The whole given scene	* //
typedef struct	s_scene{
	t_cylinder	*cylinders;
	t_sphere	*spheres;

	//	TODO: Pointer to a linked list of type plane to be added
	// t_plane		*plane;
	// t_camera		*camera;
	// t_ambient	*ambiance_light;
	// t_light		*light;

}	t_scene;

// *	General data	* //
typedef struct	s_data{
	
	// storing fd of openned file
	int		fd;
	
	// points to all object of the the scene
	t_scene		*scene;

}	t_data;

#endif
