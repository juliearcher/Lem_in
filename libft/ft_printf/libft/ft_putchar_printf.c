/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_printf.h"

void	ft_putchar_printf(char c, t_printf *str)
{
	char	*temp;

	str->output[str->length] = c;
	str->length += 1;
	str->output[str->length] = 0;
	if (str->length == str->output_length)
	{
		str->output_length += 100;
		if ((temp = (char *)malloc(str->output_length + 1)) == 0)
			exit(str->length);
		ft_memcpy(temp, str->output, str->length);
		free(str->output);
		str->output = temp;
		str->output[str->length] = 0;
	}
}
