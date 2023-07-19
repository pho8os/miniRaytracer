/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:37:15 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/19 08:48:23 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vectors.h"

typedef struct s_sphere
{
	int				type;
	t_point			center;
	double			diam;
	t_color				color;
	struct s_sphere	*next;
}	t_sphere;

#endif // SPHERE_H