/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_valid_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:18:55 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 20:02:55 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_ext(char *file)
{
	int		len;
	int		dot;
	int		i;
	char	*ber;

	len = ft_strlen(file);
	dot = 0;
	i = -1;
	ber = ".ber";
	while (i++ < len)
	{
		if (i < 4 && (file[len - 1 - i] != ber[3 - i]))
		{
			ft_printf("\033[1;31m\nError:\nMap ext not valid\033[0m\n\n");
			return (0);
		}
		if (file[i] == '.')
			dot++;
	}
	if (dot > 1)
	{
		ft_printf("\033[1;31m\nError:\nMap ext not valid\033[0m\n\n");
		return (0);
	}
	return (1);
}
