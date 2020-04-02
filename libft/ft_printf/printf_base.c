/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_first_zero(t_printf *str, uintmax_t nb)
{
	if (str->precision > ft_strlen_unsigned(nb, 8))
		return (1);
	if (nb == 0 && str->precision == 0)
		return (0);
	while (nb >= 8)
		nb = nb / 8;
	return (nb == 0);
}

static int		print_number_octal(t_printf *str, char *base,
						char *prefix, uintmax_t nb)
{
	int		length;

	length = str->precision == 0 && nb == 0 ? 0 : ft_strlen_unsigned(nb, 8);
	if (str->precision > length)
		length = str->precision;
	length += str->flags_tab[SHARP] &&
				!is_first_zero(str, nb) ? ft_strlen(prefix) : 0;
	if (!str->flags_tab[MINUS])
		print_width(str, length);
	if (str->flags_tab[SHARP] && !is_first_zero(str, nb))
		ft_putstr_printf(prefix, str);
	if (str->precision != 0)
		print_precision(str, ft_strlen_unsigned(nb, 8) +
			(str->flags_tab[SHARP] && !is_first_zero(str, nb)));
	if (str->precision != 0 || nb != 0)
		ft_putnbr_unsigned_base(nb, base, 8, str);
	if (str->flags_tab[MINUS])
		print_width(str, length);
	return (0);
}

int				print_number_base(t_printf *str, char *base,
									char *prefix, int size)
{
	uintmax_t			nb;
	int					length;

	str->flags_tab[ZERO] = str->precision != -1 ? 0 : str->flags_tab[ZERO];
	nb = get_number_unsigned(str);
	if (size == 8)
		return (print_number_octal(str, base, prefix, nb));
	length = str->precision > ft_strlen_unsigned(nb, size) ?
		str->precision : ft_strlen_unsigned(nb, size);
	length += str->flags_tab[SHARP] && nb > 0 ? ft_strlen(prefix) : 0;
	if (str->flags_tab[SHARP] && str->flags_tab[ZERO] && nb > 0)
		ft_putstr_printf(prefix, str);
	if (!str->flags_tab[MINUS])
		print_width(str, length);
	if (str->flags_tab[SHARP] && !str->flags_tab[ZERO] && nb > 0)
		ft_putstr_printf(prefix, str);
	if (str->precision != 0)
		print_precision(str, ft_strlen_unsigned(nb, size));
	if (str->precision != 0 || nb != 0)
		ft_putnbr_unsigned_base(nb, base, size, str);
	else if (str->min_width != -1)
		ft_putchar_printf(' ', str);
	if (str->flags_tab[MINUS])
		print_width(str, length);
	return (0);
}

int				printf_binary(t_printf *str)
{
	return (print_number_base(str, "01", "0b", 2));
}

int				printf_long_binary(t_printf *str)
{
	str->type = LONG;
	return (printf_binary(str));
}
