/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_valid_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:17:36 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 15:31:27 by tmoumni          ###   ########.fr       */
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

int	valid_chars(t_game *game)
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
