/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:29:30 by absaid            #+#    #+#             */
/*   Updated: 2023/07/15 02:26:41 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
# define RT_RENDER_H

# include "rt_parser.h"
# include <mlx.h>
# include <stdbool.h>

# define EPS 0.00001
# define WIDTH 900
# define HEIGHT 800

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	double	n_width;
	double	n_height;
	double	pixel;
}	t_mlx;

typedef struct s_solution
{
	double	t;
	t_point center;
	t_point inter;
	t_vec lvec;
	t_vec norm;
	t_vec Rnorm;
	t_color color;
} t_solution;

typedef struct s_eq2d
{
	double a;
	double b;
	double c;
	double t1;
	double t2;
	double delta;
} t_eq2d;

typedef struct s_ray
{
	t_point	origin;
	t_vec	direction;
	int		red;
	int		green;
}	t_ray;

typedef	struct s_intersection_utils
{
	t_data		*data;
	t_solution	T;
	t_ray		ray;
	t_mlx		mlx;
	t_light		*am;
	t_light		*l;
}	t_utils;

/* ************************************************************************** */
/*								Rendering									  */
/* ************************************************************************** */
void	rt_rendering(t_data *data);
void	ft_ray(t_cam *cam, int x, int y, t_mlx *mlx, t_ray *ray);

/* ************************************************************************** */
/*								Colors										  */
/* ************************************************************************** */
t_color coefcolor(t_color c1, t_color c2, double coef);
t_color coloradd(t_color c1, t_color c2);
t_color colormix(t_color c1, t_color c2);

/* ************************************************************************** */
/*								Intersections								  */
/* ************************************************************************** */
void	interpl(t_ray *ray, t_plane *pl, t_solution *T);
bool  intersp(t_utils *utils, t_sphere *sp);
void	find_intersections_with_objects(t_data *data, t_utils *utils);

/* ************************************************************************** */
/*								Light										  */
/* ************************************************************************** */
void    calcul_sphere_light(t_utils *utils, t_sphere *sp, double t);

/* ************************************************************************** */
/*							Vector Calculations								  */
/* ************************************************************************** */
double dot_prod(t_vec v, t_vec u);
t_vec	cross_prod(t_vec v, t_vec u);
t_vec	vecadd(t_vec v, t_vec u);
t_vec	vecxnum(t_vec v, double nb);
t_vec	vecsub(t_vec v, t_vec u);
t_vec	normvec(t_vec v);
double	lengthvec(t_vec v);

#endif // RT_RENDER_H