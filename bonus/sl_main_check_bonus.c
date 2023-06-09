/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:48:13 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/14 15:24:24 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	so_long_check(t_game *g)
{
	if (!valid_xpm(g))
		return (0);
	if (!rect_map(g))
		return (0);
	if (!valid_chars(g))
		return (0);
	if (!valid_walls(g))
		return (0);
	if (!count_p_e(g))
		return (0);
	if (!count_clctbls(g))
		return (0);
	if (!valid_path_to_c(g))
		return (0);
	if (!valid_path_to_exit(g))
		return (0);
	return (1);
}
