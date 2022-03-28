/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:51:47 by jbach             #+#    #+#             */
/*   Updated: 2022/03/20 17:39:12 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*ft_verif_params_global(char **argv)
{
	t_map	*map;

	ft_verif_params_argu(argv);
	map = ft_init_map(argv);
	ft_verif_params_map(map);
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		map = ft_verif_params_global(argv);
		map->mlx = mlx_init();
		if (map->mlx == NULL)
			return (1);
		map->window = mlx_new_window(map->mlx, 2100, 1080, "The world of MMS");
		if (map->window == NULL)
		{
			free(map->window);
			return (1);
		}
		put_img_to_file_cosperso(map);
		put_img_to_file_texture(map);
		put_img_to_window_verif(map);
		mlx_hook(map->window, 17, 1L << 5, ft_endgame, map);
		mlx_hook(map->window, 2, 1L << 0, ft_event_keyboard, map);
		mlx_loop(map->mlx);
		ft_free_all(map);
	}
	else
		ft_error("Error\nNombre  d'arguments invalides\n", NULL);
}
