/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:14:00 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/05 15:10:02 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_put_img(int i, int j, int d, t_game *g)
{
	if (g->map[i][j] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->wall, j * 32, i * 32);
	else if (g->map[i][j] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->clct, j * 32, i * 32);
	else if (g->map[i][j] == 'E' && g->clctbls != g->clcted)
		mlx_put_image_to_window(g->mlx, g->win, g->exit, j * 32, i * 32);
	else if (g->map[i][j] == 'E' && g->clctbls == g->clcted)
		mlx_put_image_to_window(g->mlx, g->win, g->open, j * 32, i * 32);
	else if (g->map[i][j] == 'P' && d == -1)
		mlx_put_image_to_window(g->mlx, g->win, g->crc_l, j * 32, i * 32);
	else if (g->map[i][j] == 'P' && (d == 1 || !d))
		mlx_put_image_to_window(g->mlx, g->win, g->crc_r, j * 32, i * 32);
	else if (g->map[i][j] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->land, j * 32, i * 32);
}
