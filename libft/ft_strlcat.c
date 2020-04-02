/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] != 0 && size > 0)
	{
		size = size - 1;
		i = i + 1;
	}
	if (size == 0)
		return (i + ft_strlen(src));
	j = 0;
	while (src[j] != 0 && size > 1)
	{
		dst[i++] = src[j++];
		size = size - 1;
	}
	dst[i] = 0;
	while (src[j] != 0)
	{
		i = i + 1;
		j = j + 1;
	}
	return (i);
}
