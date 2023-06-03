/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:38:41 by absaid            #+#    #+#             */
/*   Updated: 2023/06/03 09:04:20 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
#define RT_PARSER_H

# include "../libgc/gc.h"

enum s_type
{
	ERROR,
	SPHERE,
	CYLINDER
}	t_type;

typedef struct s_3d
{
	double		x;
	double		y;
	double		z;
}	t_vec,	t_point;

// *	All spheres	* //

typedef struct s_sphere
{
	int				type;
	t_point			center;
	double			diam;
	int				color;
	struct s_sphere	*next;
}	t_sphere;

// *	All cylinders	* //
typedef struct s_cylinder
{
	t_vec				*nvec;
	t_point				center;
	int					type;
	double				diam;
	double				height;
	int					color;
	struct s_cylinder	*next;
}	t_cylinder;

// *	The whole given scene	* //
typedef struct	s_scene{
	t_cylinder	*cylinders;
	t_sphere	*spheres;
}	t_scene;

// *	General data	* //
typedef struct	s_data{
	int		fd;
	t_scene	*scene;
}	t_data;

// *	Parsing Functions	* //

void	parse_file(t_data *data);
// void addobj(t_scene **scene, t_scene *new);
// t_scene *ft_newobj(void *obj,int type);
// char *ft_strtok(char *s, char specifier);

#endif
