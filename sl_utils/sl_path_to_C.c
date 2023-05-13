/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_to_C.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:25:01 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 16:44:53 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_path_to_c(t_game *game)
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
				if (!find_path(game->pos_x, game->pos_y, game, NULL))
				{
					ft_printf("\033[1;31mError: Invalid path to clctbl\033[0m\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}
