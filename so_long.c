/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:10:33 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/03 20:05:28 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int	w;
	int	h;

	game->land = mlx_xpm_file_to_image(game->mlx, "./imgs/land.xpm", &w, &h);
	game->crct = mlx_xpm_file_to_image(game->mlx, "./imgs/crct.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./imgs/wall.xpm", &w, &h);
	game->clct = mlx_xpm_file_to_image(game->mlx, "./imgs/clct.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./imgs/exit.xpm", &w, &h);
	game->mvmnts = 0;
	game->clcted = 0;
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up_down(game, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_up_down(game, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left_right(game, -1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_left_right(game, 1);
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}

void	read_map(char *av, t_game *game)
{
	int		fd;
	char	*line;
	char	*read;
	int		height;

	height = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening map\n");
		exit (0);
	}
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	while (line && line[0] != '\n')
	{
		read = ft_strjoinnw(read, line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	free(line);
	game->height = height;
	game->map = read;
}

int	main(int ac, char **av)
{
	t_game		*g;

	g = malloc(sizeof(t_game));
	if (ac != 2)
	{
		printf("Error args\n");
		exit (0);
	}
	read_map(av[1], g);
	if (!rect_map(g) || !map_p_e(g) || !valid_walls(g) || !map_ext(av[1]))
	{
		printf("Error check\n");
		exit (0);
	}
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, 64 * g->width, 64 * g->height, "./so_long");
	g->clctbls = count_clctbls(g);
	printf("[%d]\n", g->clctbls);
	init_game(g);
	set_imgs(g);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &exit_game, g);
	mlx_loop(g->mlx);
}
