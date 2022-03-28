/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:39:03 by jbach             #+#    #+#             */
/*   Updated: 2022/03/20 17:39:40 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_nb_ligne(char **argv)
{
	int		nb_ligne;
	char	*line;
	int		fd;

	nb_ligne = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\nProbleme de lecture de fd\n", NULL);
	line = ft_get_next_line(fd);
	while (line)
	{
		nb_ligne++;
		free(line);
		line = ft_get_next_line(fd);
	}
	free(line);
	close(fd);
	return (nb_ligne);
}

t_map	*ft_map_tab(char **argv, t_map *map)
{
	int	fd;
	int	i;
	int	nb_ligne;

	i = 0;
	nb_ligne = ft_nb_ligne(argv);
	if (nb_ligne < 3)
		ft_error("Error\nCette map a moins de 3 lignes\n", map);
	map->map_tab = malloc((nb_ligne + 1) * sizeof(char *));
	if (!(map->map_tab))
		ft_free_map(map);
	fd = open(map->name, O_RDONLY);
	map->nb_line = nb_ligne;
	while (i < map->nb_line)
	{
		map->map_tab[i] = ft_get_next_line(fd);
		i++;
	}
	map->map_tab[i] = 0;
	close(fd);
	return (map);
}

int	ft_nb_colonne_ynew(int i, t_map *map)
{
	int	y_new;

	y_new = 0;
	while (map->map_tab[i][y_new] != '\0')
		y_new++;
	return (y_new);
}

void	ft_nb_colonne(t_map *map)
{
	int	i;
	int	y_new;
	int	y_old;

	i = 0;
	y_new = 0;
	y_old = 0;
	while (i < (map->nb_line))
	{
		y_new = ft_nb_colonne_ynew(i, map);
		if (i != 0)
		{
			if (i == (map->nb_line - 1))
			{
				if (y_new + 1 != y_old)
					ft_error("Error\nProbleme de map\n", map);
			}
			else if (y_new != y_old)
				ft_error("Error\nProbleme de map\n", map);
		}
		y_old = y_new;
		i++;
	}
	map->nb_colonne = y_new;
}
