/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:56:04 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 15:13:37 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_tab(char **tab, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_printf("%c ", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}
