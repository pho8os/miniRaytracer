/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:29:30 by absaid            #+#    #+#             */
/*   Updated: 2023/07/07 23:01:22 by absaid           ###   ########.fr       */
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
	int red;
	int green;
}	t_ray;

void	rt_rendering(t_data *data);
t_ray *ft_ray(t_cam *cam, int x, int y, t_mlx *mlx, t_ray *ray);

#endif