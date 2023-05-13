/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_valid_walls_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:05:08 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 18:09:25 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error_walls(void)
{
	ft_printf("\033[1;31m\nError: map not surounded with walls\033[0m\n\n");
	return (0);
}

int	valid_walls(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g->height)
	{
		if (g->map[i][j] != '1' || g->map[i][g->width - 1] != '1')
			return (error_walls());
		i++;
	}
	i = 0;
	while (j < g->width)
	{
		if (g->map[i][j] != '1' || g->map[g->height - 1][j] != '1')
			return (error_walls());
		j++;
	}
	return (1);
}
