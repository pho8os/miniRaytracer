/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:38:24 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/19 12:14:00 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "vectors.h"
#include "render.h"

typedef	struct s_intersection_utils t_utils;

typedef struct s_light
{
	int 			type;
	t_point			pos;
	double			range;
	t_color			color;
	struct s_light	*next;
}	t_light;

void    calcul_light_for_current_pixel(t_utils *utils);
#endif // LIGHT_H