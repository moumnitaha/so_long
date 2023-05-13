/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:25:46 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 16:04:46 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_game *game)
{
	int	w;
	int	h;

	game->land = mlx_xpm_file_to_image(game->mlx, "./imgs/land.xpm", &w, &h);
	game->crc_l = mlx_xpm_file_to_image(game->mlx, "./imgs/crc_l.xpm", &w, &h);
	game->crc_r = mlx_xpm_file_to_image(game->mlx, "./imgs/crc_r.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./imgs/wall.xpm", &w, &h);
	game->clct = mlx_xpm_file_to_image(game->mlx, "./imgs/clct.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./imgs/exit.xpm", &w, &h);
	game->open = mlx_xpm_file_to_image(game->mlx, "./imgs/open.xpm", &w, &h);
	game->clctbls = count_clctbls(game);
	game->mvmnts = 0;
	game->clcted = 0;
}
