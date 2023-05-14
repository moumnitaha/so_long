/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw_imgs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:23:26 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/14 11:11:58 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*draw_imgs(t_game *g, int d)
{
	int		i;
	int		j;
	char	*moves;
	char	*clcted;

	i = -1;
	moves = ft_itoa(g->mvmnts);
	clcted = ft_itoa(g->clcted);
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
	mlx_string_put(g->mlx, g->win, 5, 5, 255255255, "Moves: ");
	mlx_string_put(g->mlx, g->win, 70, 5, 255255255, moves);
	mlx_string_put(g->mlx, g->win, 5, g->height * 27, 255255255, "Collected: ");
	mlx_string_put(g->mlx, g->win, 110, g->height * 27, 255255255, clcted);
	free(moves);
	free(clcted);
	return (0);
}
