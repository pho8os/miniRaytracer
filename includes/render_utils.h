/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:04:08 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/19 09:05:57 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_UTILS_H
# define RENDER_UTILS_H

#include "vectors.h"

typedef struct s_solution
{
	double	t;
	t_point center;
	t_point inter;
	t_vec lvec;
	t_vec norm;
	t_vec Rnorm;
	t_color color;
} t_solution;

#endif // RENDER_UTILS_H