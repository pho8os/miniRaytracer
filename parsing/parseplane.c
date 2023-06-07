/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseplane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:14:11 by absaid            #+#    #+#             */
/*   Updated: 2023/06/07 05:17:49 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

void	add_plane_back(t_plane **head, t_plane *new)
{
	t_plane	*tmp;

	if (!*head)
		return (*head = new, (void)0);
	tmp = *head;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
}

void	parsepl(t_data *data, char **s)
{
	char **const coordp = ft_split(s[1], ",", 1);
	char **const coordv = ft_split(s[2], ",", 1);
	char **const rgb = ft_split(s[3], ",", 1);
	t_plane *const pl = gc(sizeof(t_cylinder), 1);

	(s && s[4]) && (ft_error("Error : args num parseplane.c\n", 1, 0), 0); 
	(ft_strchr(",", s[1][0]) || ft_strchr(",", s[1][ft_strlen(s[1]) - 1])) && (ft_error("Error\n", 1, 0), 0);
	(ft_strchr(",", s[2][0]) || ft_strchr(",", s[2][ft_strlen(s[2]) - 1])) && (ft_error("Error\n", 1, 0), 0);
	(ft_strchr(",", s[3][0]) || ft_strchr(",", s[3][ft_strlen(s[3]) - 1])) && (ft_error("Error\n", 1, 0), 0);
	(rgb[3]) && (ft_error("Error: rgb parseplane.c\n", 1, 0), 0);
	(coordp[3]) && (ft_error("Error: 3d vector parseplane.c\n", 1, 0), 0);
	(coordv[3]) && (ft_error("Error: 3d n_vector parseplane.c\n", 1, 0), 0);
	pl->type = PLANE;
	pl->point = (t_point) {
		ft_atod(coordp[0]), 
		ft_atod(coordp[1]), 
		ft_atod(coordp[2])
	};
	pl->nvec = (t_vec) {
		ft_atod(coordv[0]), 
		ft_atod(coordv[1]), 
		ft_atod(coordv[2])
	};
	pl->color = (ft_atoi(rgb[0], 1) << 16) | (ft_atoi(rgb[1], 1) << 8) | ft_atoi(rgb[2], 1);
	pl->next = NULL;
	add_plane_back(&(data->pl), pl);
}
