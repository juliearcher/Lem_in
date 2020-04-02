/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_base.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_putnbr_unsigned_base(uintmax_t nb, char *base,
			unsigned int size, t_printf *str)
{
	if (nb >= size)
		ft_putnbr_unsigned_base(nb / size, base, size, str);
	ft_putchar_printf(base[nb % size], str);
}
