/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:26:39 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 15:28:14 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_height(int fd)
{
	int		height;
	char	*line;

	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	return (height);
}

void	remove_nl(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}

void	read_map(char *av, t_game *game)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_printf("Error: %s\n", strerror(errno));
	game->map = (char **)malloc(sizeof(char *) * get_height(fd));
	close(fd);
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	while (line)
	{
		remove_nl(line);
		game->map[height] = line;
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	game->height = height;
	player_pos(game);
}
