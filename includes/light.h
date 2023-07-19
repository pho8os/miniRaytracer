/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:38:24 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/19 08:48:59 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "vectors.h"

typedef struct s_light
{
	int 			type;
	t_point			pos;
	double			range;
	t_color			color;
	struct s_light	*next;
}	t_light;

#endif // LIGHT_H