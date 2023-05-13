/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:24:27 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 18:32:36 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_ud_lr(t_game *game, int u_d, int l_r)
{
	int			x;
	int			y;
	char		**map;
	static int	d;

	map = game->map;
	player_pos(game);
	x = game->pos_x;
	y = game->pos_y;
	if (l_r)
		d = l_r;
	if (map[y + u_d][x + l_r] == '0' || map[y + u_d][x + l_r] == 'C')
	{
		if (map[y + u_d][x + l_r] == 'C')
			game->clcted++;
		map [y][x] = '0';
		if (l_r)
			map[y][x + l_r] = 'P';
		if (u_d)
			map[y + u_d][x] = 'P';
		game->mvmnts++;
	}
	draw_imgs(game, d);
	win_game(game, y + u_d, x + l_r);
}
