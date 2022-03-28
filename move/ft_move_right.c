/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:19:12 by jbach             #+#    #+#             */
/*   Updated: 2022/03/20 16:19:11 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_right_cosmetible(t_map *map, int p_line, int p_col)
{
	char	*nb_move;

	map->count_mouv += 1;
	nb_move = ft_strjoin(ft_itoa(map->count_mouv), "\n");
	map->map_tab[p_line][p_col] = '0';
	map->map_tab[p_line][p_col + 1] = 'P';
	map->c_collect += 1;
	write(1, nb_move, ft_nb(map));
	free(nb_move);
}

void	ft_move_right_notwall(t_map *map, int p_line, int p_col)
{
	char	*nb_move;
	int		c_col;

	c_col = map->c_collect;
	if (map->map_tab[p_line][p_col + 1] == 'C')
		ft_move_right_cosmetible(map, p_line, p_col);
	else if (map->map_tab[p_line][p_col + 1] != '1')
	{
		if (map->map_tab[p_line][p_col + 1] == 'E' && c_col != map->nb_item)
			write(1, "Non, continue de manger !\n", 26);
		else if (map->map_tab[p_line][p_col + 1] != 'E')
		{
			if (map->map_tab[p_line][p_col + 1] != 'X')
			{
				map->count_mouv += 1;
				nb_move = ft_strjoin(ft_itoa(map->count_mouv), "\n");
				map->map_tab[p_line][p_col] = '0';
				map->map_tab[p_line][p_col + 1] = 'P';
				write(1, nb_move, ft_nb(map));
				free(nb_move);
			}
		}
	}
}

void	ft_move_right(t_map *map)
{
	int		p_line;
	int		p_col;
	char	*nb_move;
	int		c_col;

	c_col = map->c_collect;
	p_line = map->line_position;
	p_col = map->colonne_position;
	ft_move_right_notwall(map, p_line, p_col);
	put_img_to_window_verif(map);
	if (map->map_tab[p_line][p_col + 1] == 'E' && c_col == map->nb_item)
	{
		map->count_mouv += 1;
		nb_move = ft_strjoin(ft_itoa(map->count_mouv), "\n");
		write(1, nb_move, ft_nb(map));
		free(nb_move);
		map->map_tab[p_line][p_col] = '0';
		write(1, "Félicitation ! Tu as gagné !\n", 31);
		ft_endgame(map);
	}
}
