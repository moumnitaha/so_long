/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:53:52 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/04 15:26:23 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_imgs(t_game *g)
{
	int	i;
	int	j;
	int	d;

	j = 0;
	d = 64;
	while (j < g->height)
	{
		i = 0;
		while (i < g->width)
		{
			if (g->map[j * g->width + i] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->wall, i * d, j * d);
			else if (g->map[j * g->width + i] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->clct, i * d, j * d);
			else if (g->map[j * g->width + i] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->exit, i * d, j * d);
			else if (g->map[j * g->width + i] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->crct, i * d, j * d);
			else if (g->map[j * g->width + i] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->land, i * d, j * d);
			i++;
		}
		j++;
	}
}

int	count_clctbls(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i++ < ft_strlen(game->map))
	{
		if (game->map[i] == 'C')
			count++;
	}
	return (count);
}

void	win_game(t_game *game, int index)
{
	if (game->map[index] == 'E' && game->clcted == game->clctbls)
	{
		ft_printf("\n\033[1;32m[[[ u win ]]]\033[0m\n");
		mlx_destroy_image(game->mlx, game->win);
		exit(0);
	}
}

void	move_up_down(t_game *game, int d)
{
	int		i;
	int		width;
	char	*map;

	i = 0;
	map = game->map;
	width = game->width;
	while (map[i] && map[i] != 'P')
		i++;
	if (map[i + d * width] == '0' || map[i + d * width] == 'C')
	{
		if (map[i + d * width] == 'C')
			game->clcted++;
		map[i] = '0';
		map[i + d * width] = 'P';
		game->mvmnts++;
		ft_printf("moves: %d & clct: %d\n", game->mvmnts, game->clcted);
	}
	win_game(game, i + d * width);
	set_imgs(game);
}

void	move_left_right(t_game *game, int d)
{
	int		i;
	char	*map;

	i = 0;
	map = game->map;
	while (map[i] && map[i] != 'P')
		i++;
	if (map[i + d] == '0' || map[i + d] == 'C')
	{
		if (map[i + d] == 'C')
			game->clcted++;
		map[i] = '0';
		map[i + d] = 'P';
		game->mvmnts++;
		ft_printf("moves: %d & clct: %d\n", game->mvmnts, game->clcted);
	}
	win_game(game, i + d);
	set_imgs(game);
}
