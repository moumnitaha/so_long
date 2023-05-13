/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:10:33 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 20:05:03 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game		*g;

	g = malloc(sizeof(t_game));
	if (ac != 2)
	{
		ft_printf("Error:\n%s\n", strerror(errno));
		exit (0);
	}
	if (!valid_ext(av[1]))
		exit (0);
	read_map(av[1], g);
	player_pos(g);
	if (!so_long_check(g))
		exit (0);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, DM * g->width, DM * g->height, "./so_long");
	init_game(g);
	draw_imgs(g, 1);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &escape_game, g);
	mlx_loop(g->mlx);
}
