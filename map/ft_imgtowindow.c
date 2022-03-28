/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imgtowindow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:26:54 by jbach             #+#    #+#             */
/*   Updated: 2022/03/15 21:26:55 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_all_img_wind(t_map *map, char line_verif, int x, int y)
{
	ft_put_img_cosperso(map, line_verif, x, y);
	ft_put_img_texture(map, line_verif, x, y);
}

void	put_img_to_window(t_map *map)
{
	int		line;
	int		colonne;
	int		x;
	int		y;
	char	line_verif;

	line = 0;
	x = 0;
	y = 0;
	while (line < map->nb_line)
	{
		colonne = 0;
		x = 0;
		while (colonne < map->nb_colonne)
		{
			line_verif = map->map_tab[line][colonne];
			ft_put_all_img_wind(map, line_verif, x, y);
			ft_new_position(map, line_verif, line, colonne);
			x += 60;
			colonne++;
		}
		line++;
		y += 60;
	}
}

void	put_img_to_window_verif(t_map *map)
{
	if (map->window != NULL)
	{
		put_img_to_window(map);
	}
}
