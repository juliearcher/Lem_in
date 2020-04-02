/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static void	init_conv(t_printf *str)
{
	str->conv = "sSpdDioOuUxXcC%bBfF";
	str->f[0] = &printf_string;
	str->f[1] = &printf_string_unicode;
	str->f[2] = &printf_addr;
	str->f[3] = &printf_int;
	str->f[4] = &printf_long_int;
	str->f[5] = &printf_int;
	str->f[6] = &printf_octal;
	str->f[7] = &printf_long_octal;
	str->f[8] = &printf_unsigned;
	str->f[9] = &printf_long_unsigned;
	str->f[10] = &printf_lower_hexa;
	str->f[11] = &printf_upper_hexa;
	str->f[12] = &printf_char;
	str->f[13] = &printf_char_unicode;
	str->f[14] = &printf_percent;
	str->f[15] = &printf_binary;
	str->f[16] = &printf_long_binary;
	str->f[17] = &printf_float;
	str->f[18] = &printf_long_double;
}

static void	init_flags(t_printf *str)
{
	str->flags = "#0-+ ";
	str->flags_type[0] = "hh";
	str->flags_type[1] = "h";
	str->flags_type[2] = "ll";
	str->flags_type[3] = "l";
	str->flags_type[4] = "j";
	str->flags_type[5] = "z";
	str->flags_type[6] = "L";
}

int			init_struct(t_printf *str)
{
	init_flags(str);
	init_conv(str);
	str->output_length = 100;
	if ((str->output = (char *)malloc(str->output_length + 1)) == 0)
		return (0);
	str->output[0] = 0;
	return (1);
}

void		init_flags_tab(t_printf *str)
{
	int			i;

	i = -1;
	while (++i < NB_FLAGS_TAB)
		str->flags_tab[i] = 0;
	str->min_width = -1;
	str->precision = -1;
	str->type = -1;
	str->prev = 0;
}
