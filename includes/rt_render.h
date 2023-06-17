/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:29:30 by absaid            #+#    #+#             */
/*   Updated: 2023/06/17 12:49:45 by absaid           ###   ########.fr       */
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
} t_mlx;

void	rt_rendering(t_data *data);

#endif