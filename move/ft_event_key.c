/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:51:14 by jbach             #+#    #+#             */
/*   Updated: 2022/03/20 16:23:38 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Mac
int	ft_event_keyboard(int keycode, t_map *map)
{
	if (keycode == 2 || keycode == 124)
		ft_move_right(map);
	else if (keycode == 13 || keycode == 126)
		ft_move_up(map);
	else if (keycode == 1 || keycode == 125)
		ft_move_down(map);
	else if (keycode == 0 || keycode == 123)
		ft_move_left(map);
	else if (keycode == 53)
		ft_endgame(map);
	return (0);
}

//Linux
/*
int	ft_event_keyboard(int keycode, t_map *map)
{
	if (keycode == 65363 || keycode == 100)
		ft_move_right(map);
	else if (keycode == 65362 || keycode == 119)
		ft_move_up(map);
	else if (keycode == 65364 || keycode == 115)
		ft_move_down(map);
	else if (keycode == 65361 || keycode == 97)
		ft_move_left(map);
	else if (keycode == 65307)
		ft_endgame(map);
	return (0);
}
*/