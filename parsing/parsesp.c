/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsesp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:34:22 by absaid            #+#    #+#             */
/*   Updated: 2023/06/06 09:46:07 by mfouadi          ###   ########.fr       */
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

	sp->type = SPHERE;
	sp->center = (t_point) {
		ft_atod(coordp[0]), 
		ft_atod(coordp[1]), 
		ft_atod(coordp[2])
	};
	sp->diam = ft_atod(s[2]);
	sp->color = (ft_atoi(rgb[0], 1) << 16) | (ft_atoi(rgb[1], 1) << 8) | ft_atoi(rgb[2], 1);
	sp->next = NULL;
	add_sphere_back(&(data->sph), sp);
}
