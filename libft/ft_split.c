/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:55:28 by absaid            #+#    #+#             */
/*   Updated: 2023/06/06 23:57:44 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"../includes/minirt.h"

static int	count_words(char *str, char *c)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
		if (!ft_strchr(c, str[i]) && (ft_strchr(c, str[i + 1]) || !str[i + 1]))
			count++;
	return (count);
}


char	**ft_split(char const *s, char *c, int mode)
{
	char	**p;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = -1;
	if (!s)
		return (NULL);
	p = (char **)malloc(sizeof (char *) * (count_words((char *)s, c) + 1));
	while (++l < count_words((char *)s, c))
	{	
		while (s[i] && ft_strchr(c, s[i]))
		{
			if(mode && ft_strchr(c, s[i]) && ft_strchr(c, s[i + 1]))
				return(ft_error("Error : ft_split\n", 1, 0), NULL);
			i++;
		}
		j = i;
		while ( s[i] && !ft_strchr(c, s[i]) )
			i++;
		p[l] = ft_substr(s, j, i - j);
	}
	return (p[l] = NULL, p);
}
