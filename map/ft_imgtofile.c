/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imgtofile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:26:49 by jbach             #+#    #+#             */
/*   Updated: 2022/03/15 21:26:50 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img_to_file_cosperso(t_map *map)
{
	char	*path_mms;
	char	*path_bouche;
	void	*m;
	char	*path_enemy;

	m = map->mlx;
	path_mms = "xpm/Comestible/MMS.xpm";
	path_bouche = "xpm/Perso/Bouche.xpm";
	path_enemy = "xpm/Perso/Brosse.xpm";
	map->mms = mlx_xpm_file_to_image(m, path_mms, &map->iw, &map->iw);
	if (!map->mms)
		ft_error("Error\nProblème avec le MMS! \n", map);
	map->mouth = mlx_xpm_file_to_image(m, path_bouche, &map->iw, &map->ih);
	if (!map->mouth)
		ft_error("Error\nProblème avec la bouche ! \n", map);
	map->enemy = mlx_xpm_file_to_image(m, path_enemy, &map->iw, &map->ih);
	if (!map->enemy)
		ft_error("Error\nProblème avec l'ennemi ! \n", map);
}

void	put_img_to_file_texture(t_map *map)
{
	char	*path_herbe;
	char	*path_mur;
	char	*exit;
	void	*m;

	path_herbe = "xpm/Texture/Herbe.xpm";
	path_mur = "xpm/Texture/Mur.xpm";
	exit = "xpm/Texture/Exit.xpm";
	m = map->mlx;
	map->herbe = mlx_xpm_file_to_image(m, path_herbe, &map->iw, &map->ih);
	if (!map->herbe)
		ft_error("Error\nProblème avec l'herbe ! \n", map);
	map->mur = mlx_xpm_file_to_image(map->mlx, path_mur, &map->iw, &map->ih);
	if (!map->mur)
		ft_error("Error\nProblème avec le mur ! \n", map);
	map->exit = mlx_xpm_file_to_image(map->mlx, exit, &map->iw, &map->ih);
	if (!map->exit)
		ft_error("Error\nProblème avec la sortie! \n", map);
}
