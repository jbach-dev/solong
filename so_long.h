/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:36:13 by jbach             #+#    #+#             */
/*   Updated: 2022/03/20 15:14:44 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include <stdio.h>
# include "mlx/mlx.h"
// #include "mlx_linux/mlx.h"
// #include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map_tab;
	char	*name;
	int		nb_line;
	int		nb_colonne;
	void	*mlx;
	void	*window;
	void	*mms;
	void	*mouth;
	void	*herbe;
	void	*mur;
	void	*exit;
	void	*enemy;
	int		ih;
	int		iw;
	int		line_position;
	int		colonne_position;
	int		c_collect;
	int		nb_exit;
	int		nb_item;
	int		nb_position;
	int		line_exit;
	int		colonne_exit;
	int		count_mouv;
}	t_map;

int		main(int argc, char **argv);
t_map	*ft_map_tab(char	**argv, t_map *map);
void	put_img_to_window_verif(t_map *map);
void	put_img_to_file_texture(t_map *map);
void	put_img_to_file_cosperso(t_map *map);
int		ft_event_keyboard(int keycode, t_map *map);
void	ft_error(char *msg, t_map *map);
void	ft_nb_colonne(t_map *map);
void	ft_verif_params_argu(char **argv);
void	ft_verif_params_map(t_map *map);
int		ft_strstr(char *s, char *c);
char	*ft_strdup(const char *s1);
void	ft_move_right(t_map *map);
void	ft_move_up(t_map *map);
void	ft_move_down(t_map *map);
void	ft_move_left(t_map *map);
int		ft_endgame(t_map *map);
t_map	*ft_init_map(char **argv);
void	ft_free_all(t_map *map);
void	ft_free_map(t_map *map);
char	*ft_itoa(int n);
void	*ft_calloc(int count, int size);
void	ft_put_img_cosperso(t_map *map, char line_verif, int x, int y);
void	ft_new_position(t_map *map, char char_li, int line, int colonne);
void	ft_put_img_texture(t_map *map, char line_verif, int x, int y);
int		ft_nb(t_map *map);

#endif
