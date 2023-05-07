/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_valid_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:25:01 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/07 18:25:00 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_valid_path(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
			{
				game->clct_x = j;
				game->clct_y = i;
				if (find_path(game->pos_x, game->pos_y, game, NULL))
					ft_printf("Path found to (%d, %d)\n", j, i);
				else
				{
					ft_printf("Path Not found to (%d, %d)\n", j, i);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
