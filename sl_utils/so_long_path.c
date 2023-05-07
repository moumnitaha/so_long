/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:49:52 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/07 17:02:17 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_bzero(void *s, size_t length)
{
	size_t	count;

	count = 0;
	while (count < length)
	{
		((char *)s)[count] = '0';
		count++;
	}
}

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

int	is_valid(int x, int y, t_game *g, char **visited)
{
	if (y < 0 || y >= g->height || x < 0 || x >= g->width)
		return (0);
	if (visited[y][x] == 'V' || g->map[y][x] == '1' || g->map[y][x] == 'E')
		return (0);
	return (1);
}

int	find_path(int x, int y, t_game *g, int cord[2], char **tab)
{
	char	**visited;

	visited = tab;
	if (!visited)
		visited = alloc_tab(g);
	if (x == cord[0] && y == cord[1])
	{
		visited = free_tab(visited, g->height);
		return (1);
	}
	visited[y][x] = 'V';
	if (is_valid(x + 1, y, g, visited) && find_path(x + 1, y, g, cord, visited))
		return (1);
	if (is_valid(x, y + 1, g, visited) && find_path(x, y + 1, g, cord, visited))
		return (1);
	if (is_valid(x - 1, y, g, visited) && find_path(x - 1, y, g, cord, visited))
		return (1);
	if (is_valid(x, y - 1, g, visited) && find_path(x, y - 1, g, cord, visited))
		return (1);
	return (0);
}
