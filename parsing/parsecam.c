/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:57:10 by absaid            #+#    #+#             */
/*   Updated: 2023/07/06 19:49:13 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"

void parsecam(t_data *data, char **s)
{
	char **coordp;
	char **coordv;

	(ptrlen(s) != 4) && (ft_error("Error : parsecam.c\n", 1, 0), 0);
	(ft_strchr(",", s[1][0]) || ft_strchr(",", s[1][ft_strlen(s[1]) - 1])) && (ft_error("Error\n", 1, 0), 0);
	(ft_strchr(",", s[2][0]) || ft_strchr(",", s[2][ft_strlen(s[2]) - 1])) && (ft_error("Error\n", 1, 0), 0);
	coordp = ft_split(s[1], ",", 1);
	(ptrlen(coordp) != 3) && (ft_error("Error : parsecam.c\n", 1, 0), 0);
	coordv = ft_split(s[2], ",", 1);
	(ptrlen(coordv) != 3) && (ft_error("Error : parsecam.c\n", 1, 0), 0);
	if (data->cam)
		return (ft_error("Error : double cam parsecam.c\n", 1, 0), (void)0);
	data->cam = gc(sizeof(t_cam), 1);
	data->cam->type = CAMERA;
	data->cam->center = (t_point){
		ft_atod(coordp[0]),
		ft_atod(coordp[1]),
		ft_atod(coordp[2])};
	data->cam->forvec = (t_vec){
		ft_atod(coordv[0]),
		ft_atod(coordv[1]),
		ft_atod(coordv[2])};
	data->cam->forvec = normvec(data->cam->forvec);
	data->cam->sidevec = cross_prod((t_vec){0, 1, 0}, data->cam->forvec);
	if(!data->cam->sidevec.x && !data->cam->sidevec.y && !data->cam->sidevec.z)
		{data->cam->sidevec = cross_prod((t_vec){1, 0, 0},  data->cam->forvec);printf("HERE\n");}
	data->cam->sidevec = normvec(data->cam->sidevec);
	data->cam->upvec = cross_prod(data->cam->sidevec, data->cam->forvec);
	data->cam->upvec = normvec(data->cam->upvec);
	data->cam->FOV = ft_atoi(s[3], 0);
}
