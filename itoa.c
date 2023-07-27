/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:01:47 by bsoykan           #+#    #+#             */
/*   Updated: 2023/07/26 12:13:07 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	digit2char(unsigned long long int digit, int upper)
{
	char	res;

	if (digit < 10)
		res = ((char) digit + '0');
	else
		res = ((char) digit - 10 + 'a');
	if (upper)
		res = ft_toupper(res);
	return (res);
}

int	ft_putnbr(long long n)
{
	int	val;

	if (n >= 0)
		return (ft_putunbr_base(n, 10, 0));
	else
	{
		if (ft_putchar('-') == -1)
			return (-1);
		val = ft_putunbr_base(n * -1, 10, 0);
		if (val == -1)
			return (-1);
		return (val + 1);
	}
}

int	ft_putunbr_base(unsigned long long n, unsigned long long base, int upper)
{
	int	result;
	int	val;

	result = 0;
	if (n >= base)
	{
		val = ft_putunbr_base(n / base, base, upper);
		if (val == -1)
			return (-1);
		result += val;
		n = n % base;
	}
	if (ft_putchar(digit2char(n, upper)) == -1)
		return (-1);
	return (result + 1);
}
