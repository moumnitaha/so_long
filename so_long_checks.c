/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:05:01 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/04 12:33:24 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rect_map(t_game *game)
{
	if (game->width * game->height != ft_strlen(game->map) || !game->height)
	{
		write(1, "\033[1;31mError map shape not rectangular\n \033[0m", 39);
		return (0);
	}
	return (1);
}

int	map_p_e(t_game *game)
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
	if (e != 1)
	{	
		write(1, "\033[1;31m\nError more\\less than 1 exit\n \033[0m", 37);
		return (0);
	}
	if (p != 1)
	{
		write(1, "\033[1;31m\nError more\\less than 1 player\n \033[0m", 39);
		return (0);
	}
	return (1);
}

int	error_walls(void)
{
	printf("\033[1;31m\nError map not surounded with walls\n\033[0m");
	return (0);
}

int	valid_walls(t_game *g)
{
	int	i;
	int	width;

	i = 0;
	width = g->width;
	while (i < ft_strlen(g->map))
	{
		if (i < width && g->map[i] != '1')
			return (error_walls());
		if (i >= ft_strlen(g->map) - width && g->map[i] != '1')
			return (error_walls());
		if ((!(i % width) || !((i + 1) % width)) && g->map[i] != '1')
			return (error_walls());
		i++;
	}
	return (1);
}

int	map_ext(char *file)
{
	int		len;
	int		dot;
	int		i;
	char	*ber;

	len = ft_strlen(file);
	dot = 0;
	i = -1;
	ber = ".ber";
	while (i++ < len)
	{
		if (i < 4 && (file[len - 1 - i] != ber[3 - i]))
		{
			printf("\033[1;31m\nError map ext\n\033[0m");
			return (0);
		}
		if (file[i] == '.')
			dot++;
	}
	if (dot > 1)
	{
		printf("\033[1;31m\nError map ext\n\033[0m");
		return (0);
	}
	return (1);
}
