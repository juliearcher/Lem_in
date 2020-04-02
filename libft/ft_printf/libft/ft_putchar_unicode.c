/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_unicode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void	ft_putchar_unicode2(wchar_t c, t_printf *str)
{
	if (c < 0xFFFF && (str->precision <= -1 || str->precision >= 3))
	{
		ft_putchar_printf(((c & 0xf000) >> 12) + 0xe0, str);
		ft_putchar_printf(((c & 0x0fc0) >> 6) + 0x80, str);
		ft_putchar_printf((c & 0x003F) + 0x80, str);
		str->precision -= 3;
	}
	else if (str->precision <= -1 || str->precision >= 4)
	{
		ft_putchar_printf(((c & 0x1c0000) >> 18) + 0xf0, str);
		if (--str->precision == 0)
			return ;
		ft_putchar_printf(((c & 0x3f000) >> 12) + 0x80, str);
		if (--str->precision == 0)
			return ;
		ft_putchar_printf(((c & 0x0fc0) >> 6) + 0x80, str);
		if (--str->precision == 0)
			return ;
		ft_putchar_printf((c & 0x003F) + 0x80, str);
		--str->precision;
	}
	else
		str->precision = 0;
}

void		ft_putchar_unicode(wchar_t c, t_printf *str)
{
	if (c <= 0x7F && (str->precision <= -1 || str->precision >= 1))
	{
		ft_putchar_printf(c, str);
		--str->precision;
	}
	else if (c <= 0x7FF && (str->precision <= -1 || str->precision >= 2))
	{
		ft_putchar_printf(((c & 0x07c0) >> 6) + 0xc0, str);
		if (--str->precision == 0)
			return ;
		ft_putchar_printf((c & 0x003f) + 0x80, str);
		--str->precision;
	}
	else
		ft_putchar_unicode2(c, str);
}
