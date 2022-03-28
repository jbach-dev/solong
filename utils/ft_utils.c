/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:04:39 by jbach             #+#    #+#             */
/*   Updated: 2022/03/04 18:58:28 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (i < map->nb_line)
		{
			free(map->map_tab[i]);
			i++;
		}
		free(map->map_tab);
		free(map->name);
		free(map);
	}
}

void	ft_error(char *msg, t_map *map)
{
	write(2, msg, ft_strlen(msg));
	ft_free_map(map);
	exit(2);
}

int	ft_strstr(char *s, char *c)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (s[i] != '\0')
	{
		y = 0;
		while (s[i] == c[y] && s[i] != '\0')
		{
			i++;
			if (y == 3 && s[i] == '\0')
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

int	ft_multiplepoint(char	*s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	while (s[len] != '/' && len)
	{
		if (s[len] == '.')
			i++;
		len--;
	}
	if (i > 1)
		return (0);
	else
		return (1);
}

char	*ft_strdup(const char *s1)
{
	char		*src;
	char		*cpy;
	size_t		i;
	size_t		len;

	src = (char *)s1;
	cpy = NULL;
	len = ft_strlen(src);
	i = 0;
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (0);
	while (src[i] != '\0' && i < len)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
