/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:58:06 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/14 18:13:34 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define DM					32
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_LEFT				123
# define KEY_RIGHT				124

typedef struct s_game {
	int		height;
	int		clctbls;
	int		width;
	int		mvmnts;
	int		clcted;
	int		pos_x;
	int		pos_y;
	int		clct_x;
	int		clct_y;
	char	**map;
	void	*mlx;
	void	*win;
	char	*wall;
	char	*clct;
	char	*exit;
	char	*open;
	char	*crc_l;
	char	*crc_r;
	char	*land;
}	t_game;

int		ft_printf(const char *str, ...);
int		key_press(int keycode, t_game *game);
int		valid_ext(char *filename);
int		find_path(int x, int y, t_game *game, char **tab);
int		exit_game(t_game *game);
int		rect_map(t_game *game);
int		count_p_e(t_game *game);
int		valid_walls(t_game *game);
int		valid_path_to_c(t_game *game);
int		valid_path_to_exit(t_game *game);
int		count_clctbls(t_game *game);
int		valid_chars(t_game *game);
int		so_long_check(t_game *g);
int		valid_xpm(t_game *game);
int		map_has_nl(void);
int		error_args(void);
char	*get_next_line(int fd);
char	*ft_itoa(int n);
char	**alloc_tab(t_game *game);
void	*free_tab(char **tab, int height);
void	ft_bzero(void *s, size_t length);
void	*draw_imgs(t_game *g, int d);
void	move_ud_lr(t_game *game, int u_d, int l_r);
void	player_pos(t_game *game);
void	mlx_put_imgs(int i, int j, int d, t_game *g);
void	read_map(char *av, t_game *game);
void	init_game(t_game *game);
int		exit_game(t_game *game);
void	win_game(t_game *game, int i, int j);
int		escape_game(t_game *game);

#endif