/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:49:52 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/06 19:51:00 by tmoumni          ###   ########.fr       */
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

void	*free_tab(char **tab, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	is_valid(int x, int y, t_game *game, char **visited)
{
	if (y < 0 || y >= game->height || x < 0 || x >= game->width)
		return (0);
	if (visited[y][x] == 'V' || game->map[y][x] == '1')
		return (0);
	return (1);
}

int	find_path(int x, int y, t_game *game, char c)
{
	static char	**visited;

	if (!visited)
		visited = alloc_tab(game);
	if (game->map[y][x] == c)
	{
		free_tab(visited, game);
		return (1);
	}
	visited[y][x] = 'V';
	if (is_valid(x + 1, y, game, visited) && find_path(x + 1, y, game, c))
		return (1);
	if (is_valid(x, y + 1, game, visited) && find_path(x, y + 1, game, c))
		return (1);
	if (is_valid(x - 1, y, game, visited) && find_path(x - 1, y, game, c))
		return (1);
	if (is_valid(x, y - 1, game, visited) && find_path(x, y - 1, game, c))
		return (1);
	visited[y][x] = '0';
	return (0);
}

// void	print_tab(char **tab, t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < game->height)
// 	{
// 		j = 0;
// 		while (j < game->width)
// 		{
// 			ft_printf("%c ", tab[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// 	ft_printf("\n");
// }