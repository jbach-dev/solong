/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:50:01 by jbach             #+#    #+#             */
/*   Updated: 2022/03/21 21:50:02 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_move_up_notwall(t_map *map, int p_line, int p_col)
{
	if (map->map_tab[p_line - 1][p_col] == 'C')
	{
		map->map_tab[p_line][p_col] = '0';
		map->map_tab[p_line - 1][p_col] = 'M';
		map->c_collect += 1;
	}
	else if (map->map_tab[p_line - 1][p_col] != '1')
	{
		if (map->map_tab[p_line - 1][p_col] == 'X')
		{
			write(1, "AHHHHH !! Tu as touché la brosse à dent ! RIP\n", 48);
			ft_endgame(map);
		}
		else if (map->map_tab[p_line - 1][p_col] == 'E')
			ft_write_message(map, 1);
		else if (map->map_tab[p_line - 1][p_col] != 'Y')
		{
			map->map_tab[p_line][p_col] = '0';
			if (map->map_tab[p_line - 2][p_col] == 'C')
				map->map_tab[p_line - 1][p_col] = 'O';
			else
				map->map_tab[p_line - 1][p_col] = 'P';
		}
	}
}

void	ft_move_up(t_map *map)
{
	int	p_line;
	int	p_col;

	p_line = map->line_position;
	p_col = map->colonne_position;
	if (map->c_collect == map->nb_item)
		map->map_tab[map->line_exit][map->colonne_exit] = 'Y';
	ft_move_up_notwall(map, p_line, p_col);
	map->count_mouv += 1;
	put_img_to_window_verif(map);
	if (map->map_tab[p_line - 1][p_col] == 'Y')
	{
		map->map_tab[p_line][p_col] = '0';
		write(1, "Félicitation ! Tu as gagné !\n", 31);
		ft_endgame(map);
	}
}
