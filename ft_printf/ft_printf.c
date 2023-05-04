/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:19:31 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/25 11:14:53 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_p_prcnt(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'p')
		len += ft_putstr("0x") + ft_putptr(va_arg(args, unsigned long));
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (*(++str) == 'd' || *str == 'i')
				len += ft_putnbr(va_arg(args, int));
			else if (*str == 's')
				len += ft_putstr(va_arg(args, char *));
			else if (*str == 'c')
				len += ft_putchar(va_arg(args, int));
			else if (*str == 'x' || *str == 'X')
				len += ft_puthex(va_arg(args, unsigned int), *str);
			else
				len += u_p_prcnt(args, *str);
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	return (va_end(args), len);
}
