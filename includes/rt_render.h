/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:29:30 by absaid            #+#    #+#             */
/*   Updated: 2023/07/06 01:38:52 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
#define RT_RENDER_H

#include "../includes/minirt.h"
#include "../includes/rt_parser.h"
# include <math.h>
# include <mlx.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	double	n_width;
	double	n_height;
	double	pixel;
} t_mlx;

typedef struct s_ray
{
	t_point	origin;
	t_vec	direction;
}	t_ray;

void	rt_rendering(t_data *data);
double dot_prod(t_vec v, t_vec u);
t_vec	cross_prod(t_vec v, t_vec u);
t_vec	vecadd(t_vec v, t_vec u);
t_vec	vecxnum(t_vec v, double nb);
t_vec	vecsub(t_vec v, t_vec u);
double lengthvec(t_vec v);

#endif