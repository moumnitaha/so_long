/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:10:33 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/02 19:02:29 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int			w;
	int			h;

	game->land = mlx_xpm_file_to_image(game->ml, "./imgs/land.xpm", &w, &h);
	game->crct = mlx_xpm_file_to_image(game->ml, "./imgs/crct.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->ml, "./imgs/wall.xpm", &w, &h);
	game->clct = mlx_xpm_file_to_image(game->ml, "./imgs/clct.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->ml, "./imgs/exit.xpm", &w, &h);
	game->mvmnts = 0;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

void	read_map(char *av, t_game *game)
{
	int		fd;
	char	*line;
	char	*read;
	int		count;

	count = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	while (line)
	{
		read = ft_strjoinnw(read, line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	free(line);
	game->height = count;
	game->map = read;
}

int	main(int ac, char **av)
{
	t_game	*g;

	g = malloc(sizeof(t_game));
	if (ac != 2)
		exit (0);
	read_map(av[1], g);
	if (!check_rect_map(g) || !check_map_pe(g) || !check_walls(g))
		exit (0);
	check_player_pos(g);
	g->ml = mlx_init();
	g->win = mlx_new_window(g->ml, 64 * g->width, 64 * g->height, "./so_long");
	init_game(g);
	set_imgs(g);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_loop(g->ml);
}
