/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imgtofile_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:48:41 by jbach             #+#    #+#             */
/*   Updated: 2022/03/21 21:48:43 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_img_to_file_move(t_map *map)
{
	char	*mouth_o;
	char	*mouth_m;
	char	*mouth_w;
	void	*m;

	m = map->mlx;
	mouth_o = "xpm/Perso/Bouche-ouverte.xpm";
	mouth_w = "xpm/Perso/Bouche_droite.xpm";
	mouth_m = "xpm/Perso/Bouche-avec-MMS.xpm";
	map->mouth_o = mlx_xpm_file_to_image(m, mouth_o, &map->iw, &map->ih);
	if (!map->mouth_o)
		ft_error("Error\nProblème avec la bouche ouverte! \n", map);
	map->mouth_m = mlx_xpm_file_to_image(m, mouth_m, &map->iw, &map->ih);
	if (!map->mouth_m)
		ft_error("Error\nProblème avec la bouche qui mange! \n", map);
	map->mouth_w = mlx_xpm_file_to_image(m, mouth_w, &map->iw, &map->ih);
	if (!map->mouth_w)
		ft_error("Error\nProblème avec la bouche tournée! \n", map);
}

void	put_img_to_file_cosperso(t_map *map)
{
	char	*path_mms;
	char	*path_bouche;
	char	*path_enemy;
	void	*m;

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
	put_img_to_file_move(map);
}

void	put_img_to_file_texture(t_map *map)
{
	char	*path_herbe;
	char	*path_mur;
	char	*exit_g;
	char	*exit;
	void	*m;

	path_herbe = "xpm/Texture/Herbe.xpm";
	path_mur = "xpm/Texture/Mur.xpm";
	exit = "xpm/Texture/Exit.xpm";
	exit_g = "xpm/Texture/Exit-good.xpm";
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
	map->exit_g = mlx_xpm_file_to_image(map->mlx, exit_g, &map->iw, &map->ih);
	if (!map->exit_g)
		ft_error("Error\nProblème avec la bouche qui mange! \n", map);
}
