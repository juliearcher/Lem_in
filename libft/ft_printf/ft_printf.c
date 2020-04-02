/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int			printf_conversion(t_printf *str)
{
	int		i;

	i = 0;
	while (i < NB_CONV && *str->format != str->conv[i])
		++i;
	if (i == NB_CONV)
		return (1);
	(str->f[i])(str);
	return (0);
}

static void	print_invalid_format(t_printf *str)
{
	if (str->min_width == -1)
	{
		--str->format;
		return ;
	}
	if (!str->flags_tab[MINUS])
		print_width(str, 1);
	ft_putchar_printf(*str->format, str);
	if (str->flags_tab[MINUS])
		print_width(str, 1);
}

static int	print_format(t_printf *str)
{
	const char	*temp;

	++str->format;
	init_flags_tab(str);
	while (*str->format)
	{
		temp = 0;
		while (str->format != 0 && str->format != temp)
		{
			temp = str->format;
			set_flags(str);
			set_min_width(str);
			set_precision(str);
			set_length_modifier(str);
		}
		if (printf_conversion(str) == 1)
			print_invalid_format(str);
		return (0);
	}
	--str->format;
	return (0);
}

int			ft_printf_loop(t_printf *str, int fd)
{
	str->length = 0;
	if (!init_struct(str))
		return (0);
	while (*(str->format))
	{
		if (*(str->format) == '%')
		{
			if (print_format(str) == -1)
				return (-1);
		}
		else
			ft_putchar_printf(*(str->format), str);
		++(str->format);
	}
	va_end(str->ap);
	write(fd, str->output, str->length);
	free(str->output);
	return (str->length);
}
