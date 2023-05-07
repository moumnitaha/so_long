/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:10:33 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/07 18:45:15 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int	w;
	int	h;

	game->land = mlx_xpm_file_to_image(game->mlx, "./imgs/land.xpm", &w, &h);
	game->crc_l = mlx_xpm_file_to_image(game->mlx, "./imgs/crc_l.xpm", &w, &h);
	game->crc_r = mlx_xpm_file_to_image(game->mlx, "./imgs/crc_r.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./imgs/wall.xpm", &w, &h);
	game->clct = mlx_xpm_file_to_image(game->mlx, "./imgs/clct.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./imgs/exit.xpm", &w, &h);
	game->open = mlx_xpm_file_to_image(game->mlx, "./imgs/open.xpm", &w, &h);
	game->clctbls = count_clctbls(game);
	game->mvmnts = 0;
	game->clcted = 0;
}

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

int	main(int ac, char **av)
{
	t_game		*g;

	g = malloc(sizeof(t_game));
	if (ac != 2 || !map_ext(av[1]))
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit (0);
	}
	read_map(av[1], g);
	if (!rect_map(g) || !valid_walls(g) || !map_p_e(g)
		|| !valid_char(g) || !map_valid_path(g))
		exit (0);
	if (!count_clctbls(g))
	{
		ft_printf("Error clctbls\n");
		exit (0);
	}
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, DM * g->width, DM * g->height, "./so_long");
	init_game(g);
	set_imgs(g, 1);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &exit_game, g);
	mlx_loop(g->mlx);
}
