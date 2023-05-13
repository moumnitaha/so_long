/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:48:13 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 15:57:29 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	so_long_check(t_game *g)
{
	if (!rect_map(g) || !valid_walls(g) || !count_p_e(g) || !count_clctbls(g)
		|| !valid_chars(g) || !valid_path_to_c(g) || !valid_path_to_exit(g)
		|| !valid_xpm(g))
		return (0);
	return (1);
}
