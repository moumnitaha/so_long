/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:05:01 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/02 18:33:58 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rect_map(t_game *game)
{
	if (game->width * game->height != ft_strlen(game->map))
	{
		write(1, "\033[1;31mError map shape not rectangular\n\033[0m", 39);
		return (0);
	}
	return (1);
}

int	check_map_pe(t_game *game)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (i++ < ft_strlen(game->map))
	{
		if (game->map[i] == 'P')
			p++;
		if (game->map[i] == 'E')
			e++;
	}
	if (e > 1)
	{	
		write(1, "\033[1;31mError more than 1 exit\n\033[0m", 30);
		return (0);
	}
	if (p > 1)
	{
		write(1, "\033[1;31mError more than 1 player\n\033[0m", 32);
		return (0);
	}
	return (1);
}

int	check_walls_lr(t_game *g, int j)
{
	if (g->map[j * g->width] != '1')
	{
		printf("Error map not surounded with walls\n");
		return (0);
	}
	if (g->map[(j + 1) * g->width - 1] != '1')
	{
		printf("Error map not surounded with walls\n");
		return (0);
	}
	return (1);
}

int	check_walls(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (j < g->height)
	{
		i = 0;
		while (i < g->width && (j == 0 || j == g->height - 1))
		{
			if (g->map[i] != '1')
			{
				printf("Error map not surounded with walls\n");
				return (0);
			}
			i++;
		}
		if (!check_walls_lr(g, j))
			return (0);
		j++;
	}
	return (1);
}
