/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:11:37 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/14 18:18:34 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error_args(void)
{
	ft_printf("\033[1;31mError:\nUsage: ./so_long map.ber\n\033[0m");
	exit (0);
}
