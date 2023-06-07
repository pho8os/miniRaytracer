/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:21:20 by absaid            #+#    #+#             */

/*   Updated: 2023/06/06 09:44:52 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

void	add_cylinder_back(t_cylinder **head, t_cylinder *new)
{
	t_cylinder	*tmp;

	if (!*head)
		return (*head = new, (void)0);
	tmp = *head;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
}

void	parsecy(t_data *data, char **s)
{
	// TODO: Freeing the 3 double pointers??
	char **const coordp = ft_split(s[1], ",", 1);
	char **const coordv = ft_split(s[2], ",", 1);
	char **const rgb = ft_split(s[5], ",", 1);
	t_cylinder *const cy = gc(sizeof(t_cylinder), 1);

	(s[6]) && (ft_error("Error : args num parsecyl.c\n", 1, 0), 0);
	(ft_strchr(",", s[1][0]) || ft_strchr(",", s[1][ft_strlen(s[1]) - 1])) && (ft_error("Error\n", 1, 0), 0);
	(ft_strchr(",", s[2][0]) || ft_strchr(",", s[2][ft_strlen(s[2]) - 1])) && (ft_error("Error\n", 1, 0), 0);
	(ft_strchr(",", s[5][0]) || ft_strchr(",", s[5][ft_strlen(s[5]) - 1])) && (ft_error("Error\n", 1, 0), 0);
	(rgb[3]) && (ft_error("Error\n", 1, 0), 0);
	(coordp[3]) && (ft_error("Error\n", 1, 0), 0);
	(coordv[3]) && (ft_error("Error\n", 1, 0), 0);
	cy->type = CYLINDER;
	cy->center = (t_point) {
		ft_atod(coordp[0]), 
		ft_atod(coordp[1]), 
		ft_atod(coordp[2])
	};
	cy->nvec = (t_vec) {
		ft_atod(coordv[0]), 
		ft_atod(coordv[1]), 
		ft_atod(coordv[2])
	};
	cy->diam = ft_atod(s[3]);
	cy->height = ft_atod(s[4]);
	cy->color = (ft_atoi(rgb[0], 1) << 16) | (ft_atoi(rgb[1], 1) << 8) | ft_atoi(rgb[2], 1);
	cy->next = NULL;
	add_cylinder_back(&(data->cyl), cy);
}
