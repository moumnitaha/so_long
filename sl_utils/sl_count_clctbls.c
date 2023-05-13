/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_count_clctbls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:22:46 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 15:22:58 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_clctbls(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (!count)
		ft_printf("Error clctbls\n");
	return (count);
}
