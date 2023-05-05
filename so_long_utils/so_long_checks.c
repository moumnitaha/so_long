/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:05:01 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/05 16:57:06 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_len(t_game *game)
{
	int		len;
	char	**map;
	int		i;

	len = 0;
	i = 0;
	map = game->map;
	while (i < game->height)
	{
		len += ft_strlen(map[i]);
		i++;
	}
	return (len);
}

int	rect_map(t_game *game)
{
	if (game->width * game->height != map_len(game))
	{
		ft_printf("\033[1;31m\nError: map shape not rectangular\033[0m\n\n");
		return (0);
	}
	return (1);
}

int	map_p_e(t_game *game)
{
	int	i;
	int	j;
	int	p_e;

	i = 0;
	p_e = 0;
	j = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P' || game->map[i][j] == 'E')
				p_e++;
			j++;
		}
		i++;
	}
	if (p_e != 2)
	{	
		ft_printf("\033[1;31m\nError: more\\less than 1 exit - player\033[0m\n\n");
		return (0);
	}
	return (1);
}

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
