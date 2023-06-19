/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ranges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:26:55 by mfouadi           #+#    #+#             */
/*   Updated: 2023/06/19 13:23:37 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"

/*

◦ Sphere: NOTHING TO BE DONE HERE FOR THIS OBJECT. ALL HANDLED
	sp 0.0,0.0,20.6 12.6 10,0,255
DONE //	∗ identifier: sp
DONE //	∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6
DONE //	∗ the sphere diameter: 12.6
DONE //	∗ R,G,B colors in range [0-255]: 10, 0, 255

◦ Plane:
	pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
DONE //	∗ identifier: pl
DONE //	∗ x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
DONE // ∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
DONE //	∗ R,G,B colors in range [0-255]: 0,0,225

◦ Cylinder:
	cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
DONE //	∗ identifier: cy
DONE //	∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
DONE //	∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
DONE //	∗ the cylinder diameter: 14.2
DONE //	∗ the cylinder height: 21.42
DONE //	∗ R,G,B colors in range [0,255]: 10, 0, 255

◦ Camera:
	C -50.0,0,20 0,0,1 70
DONE //	∗ identifier: C
DONE //	∗ x,y,z coordinates of the view point: -50.0,0,20
DONE //	∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
			0.0,0.0,1.0
DONE //	∗ FOV : Horizontal field of view in degrees in range [0,180]: 70

◦ Light:
	L -40.0,50.0,0.0 0.6 10,0,255
DONE //	∗ identifier: L
DONE //	∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
DONE //	∗ the light brightness ratio in range [0.0,1.0]: 0.6
IN_PROGRESS //	∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255

 Ambient lightning:
	A 0.2 255,255,255
DONE //	∗ identifier: A
DONE //	∗ ambient lighting ratio in range [0.0,1.0]: 0.2
DONE //	∗ R,G,B colors in range [0-255]: 255, 255, 255

*/
#ifndef ERROR_NVEC
#define ERROR_NVEC "Error: invalid range for normalized 3d vector \
in range [-1, 1] parse_ranges.c"
#endif // ERROR_NVEC

#ifndef ERROR_AMB
#define ERROR_AMB "Error: ambiant light in range [0.0,1.0] parse_ranges.c"
#endif // ERROR_NVEC

#ifndef ERROR_LIGHT
#define ERROR_LIGHT "Error: the light brightness ratio in range [0.0,1.0] parse_ranges.c"
#endif // ERROR_LIGHT

static void	parse_nvec_ranges(t_vec *nvec)
{
	if (!nvec)
		ft_error(ERROR_NVEC, 1, 0);
	if ((nvec->x < -1.0 || nvec->x > 1.0) || (nvec->y < -1.0 || nvec->y > 1.0)
		|| (nvec->z < -1.0 || nvec->z > 1.0))
		ft_error(ERROR_NVEC, 1, 0);
	return ;
}

static void	parse_light_ranges(double light, double amb_light, bool check)
{
	if (check == 0)
	{
		if (light > 1.0 || light < 0)
			ft_error(ERROR_LIGHT, 1, 0);
	}
	else
	{
		if (amb_light < 0 || amb_light > 1)
			ft_error(ERROR_AMB, 1, 0);
	}
	return ;
}

void	check_ranges(t_data *data)
{
	t_cylinder	*cy_nvec;
	t_plane		*pl_nvec;

	pl_nvec = data->pl;
	while (pl_nvec)
	{
		if (pl_nvec)
			parse_nvec_ranges(&pl_nvec->nvec);
		pl_nvec = pl_nvec->next;
	}
	cy_nvec = data->cyl;
	while (cy_nvec)
	{
		if (cy_nvec)
			parse_nvec_ranges(&cy_nvec->nvec);
		cy_nvec = cy_nvec->next;
	}
	if (data->cam)
		parse_nvec_ranges(&data->cam->forvec);
	if (data->lights)
		parse_light_ranges(data->lights->range, 0, 0);
	if (data->amlight)
		parse_light_ranges(0, data->amlight->range, 1);

	return ;
}
