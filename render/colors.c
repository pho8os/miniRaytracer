/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:23:06 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/11 06:23:28 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_render.h"

t_color coefcolor(t_color color, double coef)
{
	t_color c;

	c = vecxnum(color, coef);
	(c.x > 255) && (c.x = 255);
	(c.y > 255) && (c.y = 255);
	(c.z > 255) && (c.z = 255);
	return(c);
}

t_color coloradd(t_color c1, t_color c2)
{
	t_color c;

	c = vecadd(c1, c2);
	(c.x > 255) && (c.x = 255);
	(c.y > 255) && (c.y = 255);
	(c.z > 255) && (c.z = 255);
	return(c);
}