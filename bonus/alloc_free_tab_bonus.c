/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free_tab_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:52 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 18:04:43 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**alloc_tab(t_game *game)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * game->height);
	while (i < game->height)
	{
		tab[i] = (char *)malloc(sizeof(char) * game->width);
		if (tab[i])
			ft_bzero(tab[i], game->width);
		i++;
	}
	return (tab);
}

void	*free_tab(char **tab, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}
