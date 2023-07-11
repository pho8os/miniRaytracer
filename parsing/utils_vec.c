/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:55:51 by absaid            #+#    #+#             */
/*   Updated: 2023/07/11 07:31:09 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_render.h"

double dot_prod(t_vec v, t_vec u)
{
	return(v.x * u.x + v.y * u.y + v.z * u.z);
}

t_vec	cross_prod(t_vec v, t_vec u)
{
	return((t_vec) {
		v.y * u.z - v.z * u.y,
		v.z * u.x - v.x * u.z,
		v.x * u.y - v.y * u.x
	});
}

t_vec	vecadd(t_vec v, t_vec u)
{
	return ((t_vec){u.x + v.x, u.y + v.y, u.z + v.z});
}		

t_vec	vecxnum(t_vec v, double nb)
{
	return ((t_vec){v.x * nb, v.y * nb, v.z * nb});
}

t_vec	vecsub(t_vec v, t_vec u)
{
	return(vecadd(v, vecxnum(u, -1)));
}

double lengthvec(t_vec v)
{
	return(sqrt(dot_prod(v, v)));
}

t_vec normvec(t_vec v)
{
	return(vecxnum(v, 1 / lengthvec(v)));
}
