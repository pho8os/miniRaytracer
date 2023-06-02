/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:55:51 by absaid            #+#    #+#             */
/*   Updated: 2023/06/02 16:50:23 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double dot_prod(t_vec *v, t_vec *u)
{
	return(v->x * u->x + v->y * u->y + v->z * u->z);
}

t_vec	*cross_prod(t_vec *v, t_vec *u)
{
	t_vec *const	n = gc(sizeof(t_vec), 1);
	
	*n = (t_vec) {
		v->y * u->z - v->z * u->y,
		v->z * u->x - v->x * u->z,
		v->x * u->y - v->y * u->z
	};
	return(n);
}

t_vec	*vecadd(t_vec *v, t_vec *u)
{
	t_vec *const	n = gc(sizeof(t_vec), 1);

	return (*n = (t_vec){u->x + v->x, u->y + v->y, u->z + v->z}, n);
}		

t_vec	*vecxnum(t_vec *v, double nb)
{
	t_vec	*n;

	n = gc(sizeof(t_vec), 1);
	n->x = v->x * nb;
	n->y = v->y * nb;
	n->z = v->z * nb;
	return(n);
}

t_vec	*vecsub(t_vec *v, t_vec *u)
{
	return(vecadd(v, vecxnum(u, -1)));
}

double lengthvec(t_vec *v)
{
	return(sqrt(dot_prod(v, v)));
}