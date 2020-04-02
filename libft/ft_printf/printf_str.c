/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			printf_string(t_printf *str)
{
	char	*s;
	int		length;
	int		i;

	if (str->type == 3)
		return (printf_string_unicode(str));
	if ((s = va_arg(str->ap, char *)) == 0)
		s = ("(null)");
	length = ft_strlen(s);
	if (length > str->precision && str->precision != -1)
		length = str->precision;
	if (!str->flags_tab[MINUS])
		print_width(str, length);
	i = 0;
	while (i < length)
		ft_putchar_printf(s[i++], str);
	if (str->flags_tab[MINUS])
		print_width(str, length);
	return (0);
}

static void	printf_addr_precision(t_printf *str, int size)
{
	while (size > 0)
	{
		ft_putchar_printf('0', str);
		--size;
	}
}

int			printf_addr(t_printf *str)
{
	void			*s;
	uintptr_t		nb;
	int				size;

	if (str->flags_tab[MINUS])
		str->flags_tab[ZERO] = 0;
	s = va_arg(str->ap, void *);
	nb = (uintptr_t)s;
	size = ft_strlen_unsigned(nb, 16);
	if (s == 0 && str->precision != -1)
		size = str->precision;
	if (!str->flags_tab[MINUS] && !str->flags_tab[ZERO])
		print_width(str, size + 2);
	ft_putstr_printf("0x", str);
	if (str->precision != -1)
		printf_addr_precision(str, str->precision -
			(str->precision == 0 ? 0 : ft_strlen_unsigned(nb, 16)));
	if (str->precision != 0)
		ft_putnbr_unsigned_base(nb, "0123456789abcdef", 16, str);
	if (str->flags_tab[MINUS] || str->flags_tab[ZERO])
		print_width(str, size + 2);
	return (0);
}

int			printf_char(t_printf *str)
{
	char	c;

	if (str->type == 3)
		return (printf_char_unicode(str));
	c = va_arg(str->ap, int);
	if (!str->flags_tab[MINUS])
		print_width(str, 1);
	ft_putchar_printf(c, str);
	if (str->flags_tab[MINUS])
		print_width(str, 1);
	return (0);
}

int			printf_percent(t_printf *str)
{
	if (!str->flags_tab[MINUS])
		print_width(str, 1);
	ft_putchar_printf('%', str);
	if (str->flags_tab[MINUS])
		print_width(str, 1);
	return (0);
}
