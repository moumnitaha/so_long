/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:53:52 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/05 16:55:14 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_ud_lr(game, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_ud_lr(game, 1, 0);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_ud_lr(game, 0, -1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_ud_lr(game, 0, 1);
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}

int	count_clctbls(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	set_imgs(t_game *g, int d)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (j < g->width)
		{
			mlx_put_img(i, j, d, g);
			j++;
		}
		i++;
	}
}

void	win_game(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E' && game->clcted == game->clctbls)
	{
		ft_printf("\n\033[1;32m[[ Congratulations, u win ]]\033[0m\n");
		mlx_destroy_image(game->mlx, game->win);
		exit(0);
	}
}

void	move_ud_lr(t_game *game, int u_d, int l_r)
{
	int			x;
	int			y;
	static int	d;
	char		**map;

	map = game->map;
	x = player_pos(game)[0];
	y = player_pos(game)[1];
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
		ft_printf("moves: %d & clct: %d\n", game->mvmnts, game->clcted);
	}
	set_imgs(game, d);
	win_game(game, y + u_d, x + l_r);
}
