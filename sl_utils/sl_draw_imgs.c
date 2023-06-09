/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:23:26 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 18:33:13 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*draw_imgs(t_game *g, int d)
{
	int		i;
	int		j;

	i = -1;
	mlx_clear_window(g->mlx, g->win);
	while (++i < g->height)
	{
		j = 0;
		while (j < g->width)
		{
			mlx_put_imgs(i, j, d, g);
			j++;
		}
	}
	return (0);
}
