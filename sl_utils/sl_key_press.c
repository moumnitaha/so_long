/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:22:12 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 15:22:25 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_ud_lr(game, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_ud_lr(game, 1, 0);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_ud_lr(game, 0, -1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_ud_lr(game, 0, 1);
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}
