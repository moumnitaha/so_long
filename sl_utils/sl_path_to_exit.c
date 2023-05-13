/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_to_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:34:47 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 20:03:40 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_valid_e(int x, int y, t_game *g, char **visited)
{
	if (y < 0 || y >= g->height || x < 0 || x >= g->width)
		return (0);
	if (visited[y][x] == 'V' || g->map[y][x] == '1')
		return (0);
	return (1);
}

int	find_path_e(int x, int y, t_game *g, char **tab)
{
	char	**visited;

	visited = tab;
	if (!visited)
		visited = alloc_tab(g);
	if (g->map[y][x] == 'E')
	{
		visited = free_tab(visited, g->height);
		return (1);
	}
	visited[y][x] = 'V';
	if (is_valid_e(x + 1, y, g, visited) && find_path_e(x + 1, y, g, visited))
		return (1);
	if (is_valid_e(x, y + 1, g, visited) && find_path_e(x, y + 1, g, visited))
		return (1);
	if (is_valid_e(x - 1, y, g, visited) && find_path_e(x - 1, y, g, visited))
		return (1);
	if (is_valid_e(x, y - 1, g, visited) && find_path_e(x, y - 1, g, visited))
		return (1);
	return (0);
}

int	valid_path_to_exit(t_game *game)
{
	if (!find_path_e(game->pos_x, game->pos_y, game, NULL))
	{
		ft_printf("\033[1;31mError:\nInvalid path to Exit\033[0m\n");
		return (0);
	}
	return (1);
}
