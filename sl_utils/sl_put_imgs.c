/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_put_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:14:00 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/14 10:50:05 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_put_imgs(int i, int j, int d, t_game *g)
{
	if (g->map[i][j] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->wall, j * DM, i * DM);
	else if (g->map[i][j] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->clct, j * DM, i * DM);
	else if (g->map[i][j] == 'E' && g->clctbls != g->clcted)
		mlx_put_image_to_window(g->mlx, g->win, g->exit, j * DM, i * DM);
	else if (g->map[i][j] == 'E' && g->clctbls == g->clcted)
		mlx_put_image_to_window(g->mlx, g->win, g->open, j * DM, i * DM);
	else if (g->map[i][j] == 'P' && d == -1)
		mlx_put_image_to_window(g->mlx, g->win, g->crc_l, j * DM, i * DM);
	else if (g->map[i][j] == 'P' && (d == 1 || !d))
		mlx_put_image_to_window(g->mlx, g->win, g->crc_r, j * DM, i * DM);
	else if (g->map[i][j] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->land, j * DM, i * DM);
}
