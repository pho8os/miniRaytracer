/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:55:51 by absaid            #+#    #+#             */
/*   Updated: 2023/06/01 19:31:58 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double dot_prod(t_vec *v, t_vec *u)
{
	return(v->x * u->x + v->y * u->y + v->z * u->z);
}

t_vec	*cross_prod(t_vec *v, t_vec *u)
{
	t_vec	*n;

	n = gc(sizeof(t_vec), 1);
	n->x = v->y * u->z - v->z * u->y;
	n->y = v->z * u->x - v->x * u->z;
	n->z = v->x * u->y - v->y * u->z;
	return(n);
}

t_vec	*vecadd(t_vec *v, t_vec *u)
{
	t_vec	*n;

	n = gc(sizeof(t_vec), 1);
	n->x = u->x + v->x;
	n->y = u->y + v->y;
	n->z = u->z + v->z;
	return(n);
}

t_vec	*vecscalire(t_vec *v, double nb)
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
	return(vecadd(v, vecscalire(u, -1)));
}

double lengthvec(t_vec *v)
{
	return(sqrt(dot_prod(v, v)));
}