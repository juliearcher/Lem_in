/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fits_in_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int		ft_fits_in_int(const char *str)
{
	int					i;
	int					neg;
	unsigned int		val;

	i = 0;
	val = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == ' ')
		i = i + 1;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = str[i] == '-' ? -1 : 1;
		i = i + 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((val * 10 + str[i] - '0') >
			(neg == -1 ? (unsigned)(INT_MAX) + 1 : (unsigned)INT_MAX))
			return (0);
		val = val * 10 + str[i] - '0';
		i = i + 1;
	}
	return (1);
}
