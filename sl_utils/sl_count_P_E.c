/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_count_P_E.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:03:35 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 20:04:10 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_p_e(t_game *game)
{
	int	i;
	int	j;
	int	p_e;

	i = 0;
	p_e = 0;
	j = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P' || game->map[i][j] == 'E')
				p_e++;
			j++;
		}
		i++;
	}
	if (p_e != 2)
	{	
		ft_printf("\033[1;31m\nError:\nMore\\less than 1 exit - player\033[0m\n\n");
		return (0);
	}
	return (1);
}
