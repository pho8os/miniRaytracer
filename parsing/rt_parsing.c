/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:39:57 by absaid            #+#    #+#             */
/*   Updated: 2023/06/03 08:59:50 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"
#include "../includes/minirt.h"

// *	Return type of the object
int	object_type(char *first_keyword)
{
	// TODO : Freeing double pointer `s` before each return()
	char **const s = ft_split(first_keyword, ' ');
	if (!first_keyword)
		return (ERROR);
	if(ft_strncmp(s[0], "sp", 2))
		return(SPHERE);
	if(ft_strncmp(s[0], "cy", 2))
		return(CYLINDER);
	return(ERROR);
}

// *	Check for errors in the given file.rt parameter
void	parse_file(t_data *data)
{
	(void)data;
	return ;
}
