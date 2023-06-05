/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:38:41 by absaid            #+#    #+#             */
/*   Updated: 2023/06/05 20:45:53 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
#define RT_PARSER_H
# include "../libgc/gc.h"
# include "../libft/libft.h"

/* ************************************************************************** */
/*									Enum Struct								  */
/* ************************************************************************** */

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

typedef struct s_sphere
{
	int				type;
	t_point			center;
	double			diam;
	int				color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_cam
{
	int		type;
	t_point	center;
	t_vec 	nvec;
	int		FOV;
}	t_cam;

typedef struct s_light
{
	int 			type;
	t_point			pos;
	double			range;
	int				color;
	struct s_light	*next;
}	t_light;

typedef struct s_cylinder
{
	int					type;
	t_point				center;
	double				diam;
	double				height;
	t_vec				nvec;
	int					color;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_data
{
	t_cam		*cam;
	t_cylinder	*cyl;
	t_sphere	*sph;
	t_light		*lights;
	t_light		*amlight;
} t_data;

/* ************************************************************************** */
/*							Parsing Functions								  */
/* ************************************************************************** */

void	parsecam(t_data *data, char **s);
void	parsecy(t_data *data, char **s);
void	parselight(t_data *data, char **s);
void	parsesp(t_data *data, char **s);
void	rt_parsing(t_data *data, int fd);
void	print_error_and_exit(char *error, char **to_free, int status);

#endif

