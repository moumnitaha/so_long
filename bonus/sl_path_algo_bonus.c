/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_algo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:49:52 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 18:07:43 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valid(int x, int y, t_game *g, char **visited)
{
	if (y < 0 || y >= g->height || x < 0 || x >= g->width)
		return (0);
	if (visited[y][x] == 'V' || g->map[y][x] == '1' || g->map[y][x] == 'E')
		return (0);
	return (1);
}

int	find_path(int x, int y, t_game *g, char **tab)
{
	char	**visited;

	visited = tab;
	if (!visited)
		visited = alloc_tab(g);
	if (x == g->clct_x && y == g->clct_y)
	{
		visited = free_tab(visited, g->height);
		return (1);
	}
	visited[y][x] = 'V';
	if (is_valid(x + 1, y, g, visited) && find_path(x + 1, y, g, visited))
		return (1);
	if (is_valid(x, y + 1, g, visited) && find_path(x, y + 1, g, visited))
		return (1);
	if (is_valid(x - 1, y, g, visited) && find_path(x - 1, y, g, visited))
		return (1);
	if (is_valid(x, y - 1, g, visited) && find_path(x, y - 1, g, visited))
		return (1);
	return (0);
}
