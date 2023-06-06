/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parselights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:40:59 by absaid            #+#    #+#             */
/*   Updated: 2023/06/06 08:32:48 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

void	add_light_back(t_light **head, t_light *new)
{
	t_light	*tmp;
	// int i = 0;
	if (!*head)
		return (*head = new, (void)0);
	// puts("yo");
	tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next; 
		// fprintf(stderr, "i = %d\n", i++);
	}
	tmp->next = new;
	return ;
// printf("HEY\n");
}

void	parselight(t_data *data, char **s)
{
	char **rgb;
	char **coord;
	// fprintf(stderr, "adress ->%p\n", data);
	t_light	*light; 
	// fprintf(stderr, "light ==> %p\n", light);
	if(!ft_strncmp(s[0], "A", 1))
	{
		if(data->amlight)  
			(puts("errorAM"), exit(1), 0);
		data->amlight = gc(sizeof(t_light), 1);
		data->amlight->type = AMBIENT_LIGHT;
		rgb = ft_split(s[2], ',');
		(rgb[3]) && (ft_error("Error\n", 1, 0), 0);
		data->amlight->color = (ft_atoi(rgb[0]) << 16) | (ft_atoi(rgb[1]) << 8) | ft_atoi(rgb[2]);
		return(data->amlight->range = ft_atod(s[1]), (void)0);
	}
	else
	{
		light = gc(sizeof(t_light), 1);
		light->type = LIGHT;
		coord = ft_split(s[1], ',');
		rgb = ft_split(s[3], ',');
		(rgb[3]) && (ft_error("Error\n", 1, 0), 0);
		(coord[3]) && (ft_error("Error\n", 1, 0), 0);
		(rgb[3]) && (ft_error("Error\n", 1, 0), 0);
		// printf("\n----|%s, %s, %s|-----\n" , coord[0], coord[1], coord[2]);
		light->pos = (t_point) {
		ft_atod(coord[0]), 
		ft_atod(coord[1]), 
		ft_atod(coord[2])
		};
		// printf("\n----|%f, %f, %f|-----\n" , light->pos.x, light->pos.y, light->pos.z);
		light->color = (ft_atoi(rgb[0]) << 15) | (ft_atoi(rgb[1]) << 8) | ft_atoi(rgb[2]);
		light->range = ft_atod(s[2]);
		light->next = NULL;
		return(add_light_back(&(data->lights), light));
	}
}
