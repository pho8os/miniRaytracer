/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsesp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:34:22 by absaid            #+#    #+#             */
/*   Updated: 2023/06/06 08:31:45 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

void	add_sphere_back(t_sphere **head, t_sphere *new)
{
	t_sphere	*tmp;

	if (!*head)
		return (*head = new, (void)0);
	tmp = *head;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
}

void	parsesp(t_data *data, char **s)
{
	char **const coordp = ft_split(s[1], ',');
	char **const rgb = ft_split(s[3], ',');
	t_sphere *const sp = gc(sizeof(t_sphere), 1);

	(rgb[3]) && (ft_error("Error\n", 1, 0), 0);
	(coordp[3]) && (ft_error("Error\n", 1, 0), 0);
	sp->type = SPHERE;
	sp->center = (t_point) {
		atof(coordp[0]), 
		atof(coordp[1]), 
		atof(coordp[2])
	};
	sp->diam = atof(s[2]);
	sp->color = (ft_atoi(rgb[0]) << 16) | (ft_atoi(rgb[1]) << 8) | ft_atoi(rgb[2]);
	sp->next = NULL;
	add_sphere_back(&(data->sph), sp);
}