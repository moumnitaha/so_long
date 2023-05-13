/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:48 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/13 15:09:10 by tmoumni          ###   ########.fr       */
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
