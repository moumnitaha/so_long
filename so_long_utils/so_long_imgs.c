/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:14:00 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/04 20:17:19 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_put_img(int i, int j, int d, t_game *g)
{
	if (g->map[j * g->width + i] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->wall, i * 32, j * 32);
	else if (g->map[j * g->width + i] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->clct, i * 32, j * 32);
	else if (g->map[j * g->width + i] == 'E' && g->clctbls != g->clcted)
		mlx_put_image_to_window(g->mlx, g->win, g->exit, i * 32, j * 32);
	else if (g->map[j * g->width + i] == 'E' && g->clctbls == g->clcted)
		mlx_put_image_to_window(g->mlx, g->win, g->open, i * 32, j * 32);
	else if (g->map[j * g->width + i] == 'P' && d == -1)
		mlx_put_image_to_window(g->mlx, g->win, g->crct_l, i * 32, j * 32);
	else if (g->map[j * g->width + i] == 'P' && d == 1)
		mlx_put_image_to_window(g->mlx, g->win, g->crct_r, i * 32, j * 32);
	else if (g->map[j * g->width + i] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->land, i * 32, j * 32);
}
