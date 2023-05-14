/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_rect_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:02:48 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/14 11:18:41 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (game->height == 1 || game->width * game->height != map_len(game))
	{
		ft_printf("\033[1;31m\nError:\nMap shape not rectangular\033[0m\n\n");
		return (0);
	}
	return (1);
}
