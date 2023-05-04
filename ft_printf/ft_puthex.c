/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:56:07 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/04 12:54:18 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int num, char c)
{
	int		length;
	char	*hexlow;
	char	*hexupp;

	length = 0;
	hexlow = "0123456789abcdef";
	hexupp = "0123456789ABCDEF";
	if (num < 16 && c == 'x')
		length += ft_putchar(hexlow[num]);
	else if (num < 16 && c == 'X')
		length += ft_putchar(hexupp[num]);
	else
	{
		length += ft_puthex(num / 16, c);
		length += ft_puthex(num % 16, c);
	}
	return (length);
}
