/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:53:52 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/02 15:48:57 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_imgs(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (j < g->height)
	{
		i = 0;
		while (i < g->width)
		{
			if (g->map[j * g->width + i] == '1')
				mlx_put_image_to_window(g->ml, g->win, g->wall, i * 64, j * 64);
			else if (g->map[j * g->width + i] == 'C')
				mlx_put_image_to_window(g->ml, g->win, g->clct, i * 64, j * 64);
			else if (g->map[j * g->width + i] == 'E')
				mlx_put_image_to_window(g->ml, g->win, g->exit, i * 64, j * 64);
			else if (g->map[j * g->width + i] == 'P')
				mlx_put_image_to_window(g->ml, g->win, g->crct, i * 64, j * 64);
			else
				mlx_put_image_to_window(g->ml, g->win, g->land, i * 64, j * 64);
			i++;
		}
		j++;
	}
}

void	move_up(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] && game->map[i] != 'P')
		i++;
	if (game->map[i - game->width] == '0' || game->map[i - game->width] == 'C')
	{
		if (game->map[i - game->width] == 'C')
			printf("u eated a clctb\n");
		game->map[i] = '0';
		game->map[i - game->width] = 'P';
		game->mvmnts++;
		printf("u moved: %d times(s)\n", game->mvmnts);
	}
	set_imgs(game);
}

void	move_down(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] && game->map[i] != 'P')
		i++;
	if (game->map[i + game->width] == '0' || game->map[i + game->width] == 'C')
	{
		game->map[i] = '0';
		game->map[i + game->width] = 'P';
		game->mvmnts++;
		printf("u moved: %d times(s)\n", game->mvmnts);
	}
	set_imgs(game);
}

void	move_left(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] && game->map[i] != 'P')
		i++;
	if (game->map[i - 1] == '0' || game->map[i - 1] == 'C')
	{
		game->map[i] = '0';
		game->map[i - 1] = 'P';
		game->mvmnts++;
		printf("u moved: %d times(s)\n", game->mvmnts);
	}
	set_imgs(game);
}

void	move_right(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] && game->map[i] != 'P')
		i++;
	if (game->map[i + 1] == '0' || game->map[i + 1] == 'C')
	{
		game->map[i] = '0';
		game->map[i + 1] = 'P';
		game->mvmnts++;
		printf("u moved: %d times(s)\n", game->mvmnts);
	}
	set_imgs(game);
}
