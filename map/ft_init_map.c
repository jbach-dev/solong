/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:47:50 by jbach             #+#    #+#             */
/*   Updated: 2022/03/20 17:40:10 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*ft_init_map(char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("Error\nErreur de malloc\n", map);
	map->name = ft_strdup(argv[1]);
	map = ft_map_tab(argv, map);
	map->ih = 80;
	map->iw = 80;
	map->nb_exit = 0;
	map->nb_item = 0;
	map->nb_position = 0;
	map->line_position = 0;
	map->colonne_position = 0;
	map->c_collect = 0;
	map->count_mouv = 0;
	ft_nb_colonne(map);
	return (map);
}
