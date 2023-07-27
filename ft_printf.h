/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:01:41 by bsoykan           #+#    #+#             */
/*   Updated: 2023/07/24 17:01:44 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		ft_putchar(char c);

int		ft_putstr(char *str);

int		ft_putnbr(long long n);

int		ft_putunbr_base(unsigned long long n, unsigned long long b, int u);

#endif
