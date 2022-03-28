/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:49:49 by jbach             #+#    #+#             */
/*   Updated: 2022/03/21 21:49:50 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_move_right_notwall(t_map	*map, int p_line, int p_col)
{
	if (map->map_tab[p_line][p_col + 1] == 'C')
	{
		map->map_tab[p_line][p_col] = '0';
		map->map_tab[p_line][p_col + 1] = 'M';
		map->c_collect += 1;
	}
	else if (map->map_tab[p_line][p_col + 1] != '1')
	{
		if (map->map_tab[p_line][p_col + 1] == 'X')
		{
			write(1, "AHHHHH !! Tu as touché la brosse à dent ! RIP\n", 48);
			ft_endgame(map);
		}
		else if (map->map_tab[p_line][p_col + 1] == 'E')
			ft_write_message(map, 1);
		else if (map->map_tab[p_line][p_col + 1] != 'Y')
		{
			map->map_tab[p_line][p_col] = '0';
			if (map->map_tab[p_line][p_col + 2] == 'C')
				map->map_tab[p_line][p_col + 1] = 'O';
			else
				map->map_tab[p_line][p_col + 1] = 'D';
		}
	}
}

void	ft_move_right(t_map *map)
{
	int	p_line;
	int	p_col;

	p_line = map->line_position;
	p_col = map->colonne_position;
	if (map->c_collect == map->nb_item)
		map->map_tab[map->line_exit][map->colonne_exit] = 'Y';
	ft_move_right_notwall(map, p_line, p_col);
	map->count_mouv += 1;
	put_img_to_window_verif(map);
	if (map->map_tab[p_line][p_col + 1] == 'Y')
	{
		map->map_tab[p_line][p_col] = '0';
		write(1, "Félicitation ! Tu as gagné !\n", 31);
		ft_endgame(map);
	}
}
