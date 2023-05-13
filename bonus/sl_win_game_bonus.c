/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_win_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:53:52 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 18:09:48 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	win_game(t_game *g, int i, int j)
{
	if (g->map[i][j] == 'E' && g->clcted == g->clctbls)
	{
		ft_printf("\n\033[1;32m[[ Congratulations ]]\033[0m\n");
		ft_printf("\033[1;32m[[ u win in %d moves ]]\033[0m\n", g->mvmnts);
		ft_printf("\033[1;32m[[ is that the best u can do ? ]]\033[0m\n");
		exit_game(g);
	}
}
