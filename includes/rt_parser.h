/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:38:41 by absaid            #+#    #+#             */
/*   Updated: 2023/05/30 11:14:02 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
#define RT_PARSER_H

# include "../libgc/gc.h"
typedef struct s_sphere
{
	double		x;
	double		y;
	double		z;
	double		diam;
	int			color;
}	t_sphere;

typedef struct s_nvec
{
	double		x;
	double		y;
	double		z;
}	t_nvec;

typedef struct s_cylinder
{
	double		x;
	double		y;
	double		z;
	double		diam;
	double		height;
	t_nvec		*nvec;
	int			color;
}	t_cylinder;

typedef struct s_scene
{
	int		type;
	void	*object;
	struct  s_scene *next;
}	t_scene;


t_scene *rt_parsing(int fd);
void addobj(t_scene **scene, t_scene *new);
t_scene *ft_newobj(void *obj,int type);

#endif