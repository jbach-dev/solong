/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:49:34 by jbach             #+#    #+#             */
/*   Updated: 2022/03/21 21:49:38 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_move_left_notwall(t_map *map, int p_line, int p_col)
{
	if (map->map_tab[p_line][p_col - 1] == 'C')
	{
		map->map_tab[p_line][p_col] = '0';
		map->map_tab[p_line][p_col - 1] = 'M';
		map->c_collect += 1;
	}
	else if (map->map_tab[p_line][p_col - 1] != '1')
	{
		if (map->map_tab[p_line][p_col - 1] == 'X')
		{
			write(1, "AHHHHH !! Tu as touché la brosse à dent ! RIP\n", 48);
			ft_endgame(map);
		}
		else if (map->map_tab[p_line][p_col - 1] == 'E')
			ft_write_message(map, 1);
		else if (map->map_tab[p_line][p_col - 1] != 'Y')
		{
			map->map_tab[p_line][p_col] = '0';
			if (map->map_tab[p_line][p_col - 2] == 'C')
				map->map_tab[p_line][p_col - 1] = 'O';
			else
				map->map_tab[p_line][p_col - 1] = 'P';
		}
	}
}

void	ft_move_left(t_map *map)
{
	int	p_line;
	int	p_col;

	p_line = map->line_position;
	p_col = map->colonne_position;
	if (map->c_collect == map->nb_item)
		map->map_tab[map->line_exit][map->colonne_exit] = 'Y';
	ft_move_left_notwall(map, p_line, p_col);
	map->count_mouv += 1;
	put_img_to_window_verif(map);
	if (map->map_tab[p_line][p_col - 1] == 'Y')
	{
		map->map_tab[p_line][p_col] = '0';
		write(1, "Félicitation ! Tu as gagné !\n", 31);
		ft_endgame(map);
	}
}
