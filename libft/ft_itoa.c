/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_nb_size(int n)
{
	unsigned int	nb;
	int				size;

	size = 1;
	if (n < 0)
		size = size + 1;
	nb = n >= 0 ? n : -n;
	while (nb >= 10)
	{
		nb = nb / 10;
		size = size + 1;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char			*result;
	unsigned int	nb;
	int				size;

	size = get_nb_size(n);
	nb = n >= 0 ? n : -n;
	if ((result = (char *)malloc(size + 1)) == 0)
		return (0);
	result[size] = 0;
	size = size - 1;
	while (nb >= 10)
	{
		result[size] = nb % 10 + '0';
		nb = nb / 10;
		size = size - 1;
	}
	result[size] = nb % 10 + '0';
	if (n < 0)
		result[0] = '-';
	return (result);
}
