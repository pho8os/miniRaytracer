/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:38:41 by absaid            #+#    #+#             */
/*   Updated: 2023/07/11 09:12:38 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
#define RT_PARSER_H

# include "minirt.h"

/* ************************************************************************** */
/*									Enum Struct								  */
/* ************************************************************************** */

enum s_type
{
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
}	t_vec,	t_point, t_color;

typedef struct s_sphere
{
	int				type;
	t_point			center;
	double			diam;
	t_color				color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_cam
{
	int		type;
	t_point	center;
	t_vec 	forvec;
	t_vec 	sidevec;
	t_vec 	upvec;
	int		FOV;
}	t_cam;

typedef struct s_light
{
	int 			type;
	t_point			pos;
	double			range;
	t_color			color;
	struct s_light	*next;
}	t_light;

typedef struct s_cylinder
{
	int					type;
	t_point				center;
	double				diam;
	double				height;
	t_vec				nvec;
	t_color				color;
	struct s_cylinder	*next;
}	t_cylinder;


typedef struct s_plane
{
	int					type;
	t_point				point;
	t_vec				nvec;
	t_color				color;
	struct s_plane		*next;
}	t_plane;

typedef struct s_data
{
	t_cam		*cam;
	t_cylinder	*cyl;
	t_sphere	*sph;
	t_light		*lights;
	t_plane		*pl;
	t_light		*amlight;
}	t_data;


/* ************************************************************************** */
/*							Parsing Functions								  */
/* ************************************************************************** */
void	parsecam(t_data *data, char **s);
void	parsecy(t_data *data, char **s);
void	parselight(t_data *data, char **s);
void	parsesp(t_data *data, char **s);
void	parsepl(t_data *data, char **s);
void	rt_parsing(t_data *data, int fd);
void	ft_error(char *error, int status, int opt);
double	ft_atod(char *s);
int		ptrlen(char **ptr);
void	printdata(t_data *data);
void	check_ranges(t_data *data);

#endif

