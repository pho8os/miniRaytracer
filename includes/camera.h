/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:35:05 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/19 11:08:49 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vectors.h"

typedef struct	s_cam
{
	int		type;
	t_point	center;
	t_vec 	forvec;
	t_vec 	sidevec;
	t_vec 	upvec;
	int		FOV;
}	t_cam;

#endif // CAMERA_H