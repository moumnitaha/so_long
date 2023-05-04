/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:33:02 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/04 16:40:05 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	char	*map;
	int		i;

	map = game->map;
	i = 0;
	while (i < ft_strlen(map))
	{
		if (!included_char(map[i]))
		{
			ft_printf("Error: invalid char [%c] in map\n", map[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	player_pos(t_game *game)
{
	int	pos;

	pos = 0;
	while (game->map[pos] && game->map[pos] != 'P')
		pos++;
	return (pos);
}

void	draw_map(char *map, int width)
{
	int	i;

	i = 0;
	while (i < ft_strlen(map))
	{
		if (i % width == 0)
			ft_printf("\n");
		ft_printf("%c", map[i]);
		i++;
	}
	ft_printf("\n");
}

int	valid_path(char *map, int pos, int width)
{	
	draw_map(map, width);
	while (map[pos - width] == '0')
	{
		map[pos] = '1';
		map[pos - width] = 'P';
		pos = pos - width;
	}
	draw_map(map, width);
	if (map[pos - width] == 'C')
	{
		map[pos] = '1';
		map[pos - width] = 'P';
		draw_map(map, width);
		ft_printf("EAT\n");
		return (pos - width);
	}
	return (valid_path(map, pos, width));
}
