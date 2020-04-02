/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_decimal(t_printf *str, long double nb, int length)
{
	int		i;

	i = 0;
	if (nb < 0.0)
		nb = -nb;
	ft_putchar_printf('.', str);
	while (i < str->precision && length)
	{
		nb = nb * 10;
		--length;
		++i;
	}
	nb += 0.49;
	if (i != 0)
		ft_putnbr_unsigned_base(nb, "0123456789", 10, str);
	while (i < str->precision)
	{
		ft_putchar_printf('0', str);
		++i;
	}
}

static void	printf_float_flags(t_printf *str, intmax_t nb, int mod, int *length)
{
	if (str->flags_tab[ZERO])
	{
		if (nb < 0.0)
			ft_putchar_printf('-', str);
		else if (str->flags_tab[SPACE] || str->flags_tab[PLUS])
			ft_putchar_printf(str->flags_tab[PLUS] ? '+' : ' ', str);
	}
	if (!str->flags_tab[MINUS])
		print_width(str, mod + length[0] + (length[1] > 0 ||
		str->flags_tab[SHARP]) + (str->precision > 0) + str->precision);
	if (!str->flags_tab[ZERO])
	{
		if (nb < 0.0)
			ft_putchar_printf('-', str);
		else if (str->flags_tab[SPACE] || str->flags_tab[PLUS])
			ft_putchar_printf(str->flags_tab[PLUS] ? '+' : ' ', str);
	}
}

static int	is_invalid(t_printf *str, long double nb)
{
	char	*s;
	int		length;

	if (nb == 1.0 / 0.0)
		s = "inf";
	else if (nb == -1.0 / 0.0)
		s = "-inf";
	else if (nb != nb)
		s = "nan";
	else
		return (0);
	length = ft_strlen(s);
	if (length > str->precision && str->precision != -1)
		length = str->precision;
	if (!str->flags_tab[MINUS])
		print_width(str, length);
	ft_putstr_printf(s, str);
	if (str->flags_tab[MINUS])
		print_width(str, length);
	return (1);
}

int			printf_float(t_printf *str)
{
	long double	nb;
	int			length[2];
	int			mod;

	nb = get_float(str);
	if (is_invalid(str, nb))
		return (0);
	if (str->flags_tab[MINUS])
		str->flags_tab[ZERO] = 0;
	if (str->precision == -1)
		str->precision = 6;
	else if (str->precision == 0)
		nb += nb > 0.0 ? 0.49 : -0.49;
	ft_strlen_float_unsigned(nb < 0 ? -nb : nb, length, str->precision);
	mod = ((long)nb < 0 || str->flags_tab[SPACE] || str->flags_tab[PLUS]);
	printf_float_flags(str, nb, mod, length);
	ft_putnbr_unsigned_base(nb < 0.0 ? -nb : nb, "0123456789", 10, str);
	if (str->precision != 0 || str->flags_tab[SHARP])
		print_decimal(str, nb - (long)nb, length[1]);
	if (str->flags_tab[MINUS])
		print_width(str, mod + length[0] + (length[1] > 0 ||
		str->flags_tab[SHARP]) + (str->precision > 0) + str->precision);
	return (0);
}

int			printf_long_double(t_printf *str)
{
	str->type = LONG;
	return (printf_float(str));
}
