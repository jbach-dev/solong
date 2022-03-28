/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_screen_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:02:47 by jbach             #+#    #+#             */
/*   Updated: 2022/03/20 16:31:57 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_supp_pixel(t_map *map)
{
	int	k;
	int	i;

	k = 490;
	i = 1050;
	while (k != 530)
	{
		i = 1050;
		while (i != 1150)
			mlx_pixel_put(map->mlx, map->window, i++, k, 0);
		k++;
	}
}

void	ft_supp_pixel_error(t_map *map)
{
	int	k;
	int	i;

	k = 490;
	i = 300;
	while (k != 530)
	{
		i = 300;
		while (i != 1150)
			mlx_pixel_put(map->mlx, map->window, i++, k, 0);
		k++;
	}
}

void	ft_write_message(t_map *map, int error)
{
	char	*message;

	if (error == 0)
	{
		ft_supp_pixel(map);
		message = ft_strjoin(ft_itoa(map->count_mouv), " pas effetues");
		mlx_string_put(map->mlx, map->window, 1050, 500, 10996055, message);
		free(message);
		message = ft_strjoin(ft_itoa(map->c_collect), " MMs engloutis");
		mlx_string_put(map->mlx, map->window, 1050, 520, 3700608, message);
		free(message);
	}
	else if (error == 1)
	{
		ft_supp_pixel_error(map);
		message = "MAIS ! Il te reste des Mms !";
		mlx_string_put(map->mlx, map->window, 300, 500, 10996055, message);
	}
}
