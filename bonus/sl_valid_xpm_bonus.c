/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_valid_xpm_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:49:20 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 18:09:40 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_xpm(t_game *game)
{
	if (!game->crc_l)
		return (0);
	if (!game->crc_r)
		return (0);
	if (!game->land)
		return (0);
	if (!game->exit)
		return (0);
	if (!game->open)
		return (0);
	if (!game->clct)
		return (0);
	if (!game->wall)
		return (0);
	return (1);
}

int	valid_xpm(t_game *game)
{
	if (!check_xpm(game))
	{
		ft_printf("Error: unvalid Texture\n");
		return (0);
	}
	return (1);
}
