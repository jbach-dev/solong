/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:50:18 by jbach             #+#    #+#             */
/*   Updated: 2022/03/20 16:33:54 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_close_window(t_map *map)
{
	mlx_destroy_image(map->mlx, map->mur);
	mlx_destroy_image(map->mlx, map->herbe);
	mlx_destroy_image(map->mlx, map->mouth);
	mlx_destroy_image(map->mlx, map->mms);
	mlx_destroy_image(map->mlx, map->exit);
	mlx_destroy_image(map->mlx, map->exit_g);
	mlx_destroy_image(map->mlx, map->mouth_m);
	mlx_destroy_image(map->mlx, map->mouth_o);
	mlx_destroy_image(map->mlx, map->mouth_w);
	mlx_destroy_image(map->mlx, map->enemy);
	mlx_destroy_window(map->mlx, map->window);
	free(map->mlx);
}

//Linux
/*
void	ft_close_window(t_map *map)
{
	mlx_destroy_image(map->mlx, map->mur);
	mlx_destroy_image(map->mlx, map->herbe);
	mlx_destroy_image(map->mlx, map->mouth);
	mlx_destroy_image(map->mlx, map->mms);
	mlx_destroy_image(map->mlx, map->exit);
	mlx_destroy_image(map->mlx, map->exit_g);
	mlx_destroy_image(map->mlx, map->mouth_m);
	mlx_destroy_image(map->mlx, map->mouth_o);
	mlx_destroy_image(map->mlx, map->mouth_w);
	mlx_destroy_image(map->mlx, map->enemy);
	mlx_destroy_window(map->mlx, map->window);
	// mlx_destroy_display(map->mlx);
	free(map->mlx);
}
*/
void	ft_free_all(t_map *map)
{
	ft_free_map(map);
}

int	ft_endgame(t_map *map)
{
	ft_close_window(map);
	ft_free_all(map);
	exit (1);
}
