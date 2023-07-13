/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:12:31 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/11 09:19:36 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_render.h"

void	find_intersections_with_objects(t_data *data, t_utils *utils)
{
    t_sphere    *sphere;

    
    utils->l = data->lights;
    utils->am = data->amlight;
    sphere = data->sph;

    while(sphere)
    {
        intersp(utils, sphere);


        sphere = sphere->next;
    }
    if(utils->T.t > EPS)
        calcul_sphere_light(utils, sphere, utils->T.t);


	return ;
}