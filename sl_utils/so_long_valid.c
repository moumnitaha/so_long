/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:33:02 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/07 14:47:22 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->clct);
	mlx_destroy_image(game->mlx, game->crc_l);
	mlx_destroy_image(game->mlx, game->crc_r);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->open);
	mlx_destroy_image(game->mlx, game->land);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	included_char(char c)
{
	char	*chars;
	int		i;

	i = 0;
	chars = "01CPE";
	while (i < 5)
	{
		if (c == chars[i])
			return (1);
		i++;
	}
	return (0);
}

int	valid_char(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = game->map;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (!included_char(map[i][j]))
			{
				ft_printf("\033[1;31m\nError: invalid char in map\033[0m\n\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->pos_x = j;
				game->pos_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
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
			ft_printf("\033[1;31m\nError: map ext not valid\033[0m\n\n");
			return (0);
		}
		if (file[i] == '.')
			dot++;
	}
	if (dot > 1)
	{
		ft_printf("\033[1;31m\nError: map ext not valid\033[0m\n\n");
		return (0);
	}
	return (1);
}
