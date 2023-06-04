/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:38:41 by absaid            #+#    #+#             */
/*   Updated: 2023/06/04 21:23:43 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
#define RT_PARSER_H

# include "../libgc/gc.h"
# include "../libft/libft.h"
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

typedef struct s_3d
{
	double		x;
	double		y;
	double		z;
}	t_vec,	t_point;

typedef struct s_sphere
{
	int type;
	t_point center;
	double		diam;
	int			color;
	struct s_sphere *next;
}	t_sphere;

typedef struct s_cam
{
	int type;
	t_point center;
	t_vec 	nvec;
	int FOV;
}	t_cam;

typedef struct s_light
{
	int type;
	t_point pos;
	double range;
	int color;
	struct s_light *next;
}	t_light;

typedef struct s_cylinder
{
	int type;
	t_point		center;
	double		diam;
	double		height;
	t_vec		nvec;
	int			color;
	struct s_cylinder *next;
}	t_cylinder;

typedef struct s_data
{
	t_cam	*cam;
	t_cylinder *cyl;
	t_sphere *sph;
	t_light *lights;
	t_light *amlight;
} t_data;

// t_scene *rt_parsing(int fd);
// void addobj(t_scene **scene, t_scene *new);
// t_scene *ft_newobj(void *obj,int type);
// char *ft_strtok(char *s, char specifier);
void	parsecam(t_data *data, char **s);
void	parsecy(t_data *data, char **s);
void	parselight(t_data *data, char **s);
void	parsesp(t_data *data, char **s);
void	rt_parsing(t_data *data, int fd);

#endif