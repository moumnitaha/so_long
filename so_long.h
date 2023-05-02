/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:58:06 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/02 17:06:05 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124

typedef struct s_game {
	int		height;
	int		width;
	int		mvmnts;
	void	*ml;
	void	*win;
	char	*map;
	char	*wall;
	char	*clct;
	char	*exit;
	char	*crct;
	char	*land;
}	t_game;

char	*get_next_line(int fd);
void	set_imgs(t_game *g);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		check_rect_map(t_game *game);
int		check_map_pe(t_game *game);

#endif