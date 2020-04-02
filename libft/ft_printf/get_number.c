/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		get_number_unsigned(t_printf *str)
{
	uintmax_t			nb;

	if (str->type == -1)
		nb = va_arg(str->ap, unsigned int);
	else if (str->type == 0)
		nb = (unsigned char)va_arg(str->ap, unsigned int);
	else if (str->type == 1)
		nb = (unsigned short)va_arg(str->ap, unsigned int);
	else if (str->type == 2)
		nb = va_arg(str->ap, unsigned long long);
	else if (str->type == 3)
		nb = va_arg(str->ap, unsigned long);
	else if (str->type == 4)
		nb = va_arg(str->ap, uintmax_t);
	else
		nb = va_arg(str->ap, size_t);
	return (nb);
}

intmax_t		get_number(t_printf *str)
{
	intmax_t			nb;

	if (str->type == -1)
		nb = va_arg(str->ap, int);
	else if (str->type == 0)
		nb = (char)va_arg(str->ap, int);
	else if (str->type == 1)
		nb = (short)va_arg(str->ap, int);
	else if (str->type == 2)
		nb = va_arg(str->ap, long long);
	else if (str->type == 3)
		nb = va_arg(str->ap, long);
	else if (str->type == 4)
		nb = va_arg(str->ap, intmax_t);
	else
		nb = va_arg(str->ap, size_t);
	return (nb);
}

long double		get_float(t_printf *str)
{
	long double		nb;

	if (str->type == -1)
		nb = va_arg(str->ap, double);
	else if (str->type == 3)
		nb = va_arg(str->ap, double);
	else
		nb = va_arg(str->ap, long double);
	return (nb);
}
