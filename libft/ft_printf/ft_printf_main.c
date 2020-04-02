/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dprintf(int fd, const char *format, ...)
{
	t_printf	str;

	if (format == 0)
		return (-1);
	va_start(str.ap, format);
	str.format = format;
	return (ft_printf_loop(&str, fd));
}

int			ft_printf(const char *format, ...)
{
	t_printf	str;

	if (format == 0)
		return (-1);
	va_start(str.ap, format);
	str.format = format;
	return (ft_printf_loop(&str, 1));
}
