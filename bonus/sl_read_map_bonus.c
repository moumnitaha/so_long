/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_read_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:26:39 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/14 18:01:31 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_height(int fd, t_game *game)
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
	game->height = height;
	return (height);
}

void	remove_nl(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}

void	valid_fd(int fd)
{
	if (fd == -1)
	{
		ft_printf("Error:\n%s\n", strerror(errno));
		exit (0);
	}
}

int	has_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	read_map(char *av, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av, O_RDONLY);
	valid_fd(fd);
	game->map = (char **)malloc(sizeof(char *) * get_height(fd, game));
	close(fd);
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	i = 0;
	while (line)
	{
		if (i == game->height - 1 && has_nl(line))
			map_has_nl();
		remove_nl(line);
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}
