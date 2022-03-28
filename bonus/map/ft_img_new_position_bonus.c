/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_new_position_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:48:25 by jbach             #+#    #+#             */
/*   Updated: 2022/03/21 21:48:29 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_new_position(t_map *map, char char_li, int line, int colonne)
{
	if (char_li == 'P' || char_li == 'O' || char_li == 'M' || char_li == 'D' )
	{
		map->line_position = line;
		map->colonne_position = colonne;
	}
	else if (char_li == 'E' || char_li == 'Y')
	{
		map->line_exit = line;
		map->colonne_exit = colonne;
	}
}

void	ft_put_img_cosperso(t_map *map, char line_verif, int x, int y)
{
	if (line_verif == 'P')
		mlx_put_image_to_window(map->mlx, map->window, map->mouth, x, y);
	else if (line_verif == 'C')
		mlx_put_image_to_window(map->mlx, map->window, map->mms, x, y);
	else if (line_verif == 'O')
		mlx_put_image_to_window(map->mlx, map->window, map->mouth_o, x, y);
	else if (line_verif == 'M')
		mlx_put_image_to_window(map->mlx, map->window, map->mouth_m, x, y);
	else if (line_verif == 'D')
		mlx_put_image_to_window(map->mlx, map->window, map->mouth_w, x, y);
	else if (line_verif == 'X')
		mlx_put_image_to_window(map->mlx, map->window, map->enemy, x, y);
}

void	ft_put_img_texture(t_map *map, char line_verif, int x, int y)
{
	if (line_verif == '1')
		mlx_put_image_to_window(map->mlx, map->window, map->mur, x, y);
	else if (line_verif == '0')
		mlx_put_image_to_window(map->mlx, map->window, map->herbe, x, y);
	else if (line_verif == 'E')
		mlx_put_image_to_window(map->mlx, map->window, map->exit, x, y);
	else if (line_verif == 'Y')
		mlx_put_image_to_window(map->mlx, map->window, map->exit_g, x, y);
}
