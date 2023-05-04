/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:46:02 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/04 12:54:21 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int			length;
	long int	nbr;

	length = 0;
	nbr = (long int)num;
	if (nbr < 0)
	{
		nbr *= -1;
		length += ft_putchar('-');
	}
	if (nbr < 10)
		length += ft_putchar(nbr + '0');
	else
	{
		length += ft_putnbr(nbr / 10);
		length += ft_putnbr((nbr % 10));
	}
	return (length);
}
