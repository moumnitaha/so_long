/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:05:01 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/02 17:05:31 by tmoumni          ###   ########.fr       */
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
