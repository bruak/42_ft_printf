/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:55:46 by bsoykan           #+#    #+#             */
/*   Updated: 2023/07/27 14:55:21 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	print_pointer_format(unsigned long long nb)
{
	int	res;

	if (ft_putstr("0x") == -1)
		return (-1);
	res = ft_putunbr_base(nb, 16, 0);
	if (res == -1)
		return (-1);
	return (res + 2);
}

unsigned int	get_uint(va_list arg)
{
	return ((unsigned int) va_arg(arg, unsigned int));
}

unsigned long long	get_ulonglong(va_list arg)
{
	return ((unsigned long long) va_arg(arg, unsigned long long));
}

int	print_format(char format_char, va_list arg)
{
	if (format_char == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format_char == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format_char == 'd' || format_char == 'i')
		return (ft_putnbr((int) va_arg(arg, int)));
	else if (format_char == 'u')
		return (ft_putunbr_base(get_uint(arg), 10, 0));
	else if (format_char == 'x')
		return (ft_putunbr_base(get_uint(arg), 16, 0));
	else if (format_char == 'X')
		return (ft_putunbr_base(get_uint(arg), 16, 1));
	else if (format_char == 'p')
		return (print_pointer_format(get_ulonglong(arg)));
	else
		return (ft_putchar(format_char));
}

int	ft_printf(const char *format, ...)
{
	int		sum_len;
	int		val;
	va_list	arguments;

	va_start (arguments, format);
	sum_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			val = print_format(*(++format), arguments);
			if (val == -1)
				return (-1);
			sum_len += val;
		}
		else
		{
			if (ft_putchar(*format) == -1)
				return (-1);
			sum_len++;
		}
		format++;
	}
	va_end(arguments);
	return (sum_len);
}

