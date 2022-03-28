/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_params_map_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:47:48 by jbach             #+#    #+#             */
/*   Updated: 2022/03/20 17:39:57 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_atleast1_verif(t_map	*map, int i, int y)
{
	if (map->map_tab[i][y] == 'E')
		map->nb_exit += 1;
	else if (map->map_tab[i][y] == 'C')
		map->nb_item += 1;
	else if (map->map_tab[i][y] == 'P')
		map->nb_position += 1;
}

void	ft_atleast1(t_map *map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < map->nb_line)
	{
		y = 0;
		while (y < map->nb_colonne)
		{
			ft_atleast1_verif(map, i, y);
			y++;
		}
		i++;
	}
	if ((map->nb_exit || map->nb_item || map->nb_position) == 0)
		ft_error("Error\nProblème d'éléments de la carte\n", map);
}

void	ft_rectangle(t_map *map)
{
	if (map->nb_colonne == map->nb_line)
		ft_error("Error\nCette carte est un carré\n", map);
}

void	ft_close(t_map	*map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < map->nb_line)
	{
		if (map->map_tab[i][0] != '1')
			ft_error("Error\nProbleme de map\n", map);
		else if (map->map_tab[i][map->nb_colonne - 1] != '1')
			ft_error("Error\nProbleme de map\n", map);
		y = 0;
		while (y < map->nb_colonne)
		{
			if ((map->map_tab[0][y]) != '1')
				ft_error("Error\nProbleme de map\n", map);
			else if (map->map_tab[map->nb_line - 1][y] != '1')
				ft_error("Error\nProbleme de map\n", map);
			y++;
		}
		i++;
	}
}

void	ft_verif_params_map(t_map *map)
{
	ft_atleast1(map);
	ft_rectangle(map);
	ft_close(map);
}
