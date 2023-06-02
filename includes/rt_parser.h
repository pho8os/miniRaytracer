/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:38:41 by absaid            #+#    #+#             */
/*   Updated: 2023/06/02 21:13:45 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
#define RT_PARSER_H

# include "../libgc/gc.h"


typedef struct s_object
{
	int		type;
}	t_object;

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
	t_object *next;
}	t_sphere;

typedef struct s_cylinder
{
	int type;
	t_point		center;
	double		diam;
	double		height;
	t_vec		*nvec;
	int			color;
	t_object *next;
}	t_cylinder;


typedef struct s_data{
	data type camera
	data type light
	data type ambiant
	
} t_data;
// t_scene *rt_parsing(int fd);
// void addobj(t_scene **scene, t_scene *new);
// t_scene *ft_newobj(void *obj,int type);
char *ft_strtok(char *s, char specifier);

#endif