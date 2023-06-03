/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:38:41 by absaid            #+#    #+#             */
/*   Updated: 2023/06/03 13:31:51 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
#define RT_PARSER_H


typedef struct s_data	t_data;
/* ************************************************************************** */
/*									Enum Struct								  */
/* ************************************************************************** */

//	Object types
enum s_type
{
	// Use of ERROR is optional for readability purposes
	ERROR,
	LIGHT,
	PLANE,
	CAMERA,
	SPHERE,
	CYLINDER,
	AMBIENT_LIGHT
} t_type;

/* ************************************************************************** */
/*							Linked list of each object						  */
/* ************************************************************************** */

// * Vector
typedef struct s_3d
{
	double		x;
	double		y;
	double		z;
}	t_vec,	t_point;

// *	All Planes in scene		* //
typedef struct s_plane
{
	int		identifier;
	t_vec	*vec;
	// TODO: Refer to the subject to know the rest of variables needed
}	t_plane;

// *	All spheres in scene	* //
typedef struct s_sphere
{
	int				identifier;
	t_point			center;
	double			diam;
	int				color;
	struct s_sphere	*next;
}	t_sphere;

// *	All cylinders in scene	* //
typedef struct s_cylinder
{
	t_vec				*nvec;
	t_point				center;
	int					identifier;
	double				diam;
	double				height;
	int					color;
	struct s_cylinder	*next;
}	t_cylinder;

//	TODO: Structures
// t_plane		*plane;
// t_camera		*camera;
// t_ambient	*ambiance_light;
// t_light		*light;

/* ************************************************************************** */
/*							Used For Parsing								  */
/* ************************************************************************** */

// *	Parse the scene's file given as an argument to this program
void	parse_file_and_initialize_scene(t_data *data);
// *	Frees a char **
void	free_pointers(char **str);
// *	Free the **to_free, print an error in STDERR then exit(status)
void	print_error_and_exit(char *error, char **to_free, int status);

#endif

