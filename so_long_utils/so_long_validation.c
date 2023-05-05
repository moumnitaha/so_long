/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:33:02 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/05 16:57:10 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_game(t_game *game)
{
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

int	*player_pos(t_game *game)
{
	int	i;
	int	j;
	int	*pos;

	i = 0;
	pos = malloc(sizeof(int) * 2);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				pos[0] = j;
				pos[1] = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (pos);
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

// void	draw_map(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < game->height)
// 	{
// 		j = 0;
// 		while (game->map[i][j])
// 		{
// 			ft_printf("%c", game->map[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// }
