/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_escape_game_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:34:27 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 18:05:37 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	escape_game(t_game *game)
{
	ft_printf("\033[1;31m[[ U gaved up :/ ]]\033[0m\n");
	return (exit_game(game));
}
