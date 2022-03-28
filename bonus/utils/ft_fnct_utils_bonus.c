/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fnct_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:46:05 by jbach             #+#    #+#             */
/*   Updated: 2022/03/21 21:46:07 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_bzero(void *s, int n)
{
	char	*source;
	int		i;

	i = 0;
	source = (char *)s;
	while (i < n)
	{
		source[i] = 0;
		i++;
	}
}

void	*ft_calloc(int count, int size)
{
	void	*pointeur;
	int		memory;

	memory = count * size;
	pointeur = malloc(memory);
	if (!pointeur)
		return (0);
	ft_bzero(pointeur, memory);
	return (pointeur);
}

int	ft_nb(t_map *map)
{
	int	nb;
	int	count;

	count = 2;
	nb = map->count_mouv;
	while (nb >= 10)
	{
		nb /= 10;
		count ++;
	}
	return (count);
}
