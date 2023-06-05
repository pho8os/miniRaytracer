/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:57:10 by absaid            #+#    #+#             */
/*   Updated: 2023/06/04 21:23:21 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"

void	parsecam(t_data *data, char **s)
{
	char **const coordp = ft_split(s[1], ',');
	char **const coordv = ft_split(s[2], ',');
	
	if (data->cam)
		return (puts("cam is already exist"), exit(1), (void)0);//ft_error
	data->cam = gc(sizeof(t_cam), 1);
	data->cam->type = CAMERA;
	data->cam->center = (t_point) {
		atof(coordp[0]), 
		atof(coordp[1]), 
		atof(coordp[2])
		};
	data->cam->nvec = (t_vec) {
		atof(coordv[0]), 
		atof(coordv[1]), 
		atof(coordv[2])
		};
	data->cam->FOV = ft_atoi(s[3]);
	if (s[4])
		return (puts("num of args invalid"), exit(0), (void)0);
}

