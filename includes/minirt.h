/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:58:50 by absaid            #+#    #+#             */
/*   Updated: 2023/07/19 09:15:19 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>

# include "gc.h"
# include "libft.h"


# define EPS 0.00001
# define WIDTH 900
# define HEIGHT 800

# define DESTROY	17
# define KEYBOARD	2

#include "camera.h"
#include "cylinder.h"
#include "light.h"
#include "sphere.h"
#include "plane.h"
#include "render.h"

/* ************************************************************************** */
/*							Linked list of each object						  */
/* ************************************************************************** */


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
/*								Rendering									  */
/* ************************************************************************** */
void	rt_rendering(t_data *data, t_utils *utils);
void	ft_ray(t_cam *cam, int x, int y, t_mlx *mlx, t_ray *ray);
void	put_pixel_on_image(t_img *img, int x, int y, int color);

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
bool	ray_cylinder_intersection(t_utils *utils, t_cylinder *cyl);
void	find_intersections_with_objects(t_data *data, t_utils *utils);


/* ************************************************************************** */
/*								Light										  */
/* ************************************************************************** */
void    calcul_sphere_light(t_utils *utils, t_sphere *sp);

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

/* ************************************************************************** */
/*								Rendering									  */
/* ************************************************************************** */
void	rt_rendering(t_data *data, t_utils *utils);
void	ft_ray(t_cam *cam, int x, int y, t_mlx *mlx, t_ray *ray);
void	put_pixel_on_image(t_img *img, int x, int y, int color);

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
bool	ray_cylinder_intersection(t_utils *utils, t_cylinder *cyl);
void	find_intersections_with_objects(t_data *data, t_utils *utils);


/* ************************************************************************** */
/*								Light										  */
/* ************************************************************************** */
void    calcul_sphere_light(t_utils *utils, t_sphere *sp);

#ifndef ERROR_MSG
# define ERROR_MSG "ERROR: incorect Input\n"
#endif // FOV_ERROR

#endif
