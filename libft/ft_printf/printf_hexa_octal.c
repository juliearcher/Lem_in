/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa_octal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				printf_octal(t_printf *str)
{
	return (print_number_base(str, "01234567", "0", 8));
}

int				printf_long_octal(t_printf *str)
{
	str->type = LONG;
	return (printf_octal(str));
}

int				printf_lower_hexa(t_printf *str)
{
	return (print_number_base(str, "0123456789abcdef", "0x", 16));
}

int				printf_upper_hexa(t_printf *str)
{
	return (print_number_base(str, "0123456789ABCDEF", "0X", 16));
}
