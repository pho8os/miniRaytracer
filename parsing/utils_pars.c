/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:57:10 by absaid            #+#    #+#             */
/*   Updated: 2023/06/02 19:43:14 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

// t_scene *ft_newobj(void *obj,int type)
// {
// 	t_scene *node;

// 	node = gc(sizeof(t_scene), 1);
// 	node->object = obj;
// 	node->type = type;
// 	node->next = NULL;
// 	return (node);
// }

// void addobj(t_scene **scene, t_scene *new)
// {
// 	(*scene) && (new -> next = *scene);
// 	*scene = new;
// }

char *ft_strtok(char *s, char specifier)
{
	static char *buffer;
	char *token;

	if (!buffer)
		buffer = s;
	if (!*buffer)
		return NULL;
	token = buffer;
	while (*buffer && *buffer != specifier)
		buffer++;
	while(*buffer == specifier && *buffer)
	{
		*buffer = 0;
		buffer++;
	}		
	return(token);
}