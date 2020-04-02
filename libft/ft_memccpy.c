/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	stop;
	char			*s1;
	char			*s2;
	size_t			i;

	s1 = (char *)dst;
	s2 = (char *)src;
	stop = (unsigned char)c;
	i = -1;
	while (++i < n && (unsigned char)s2[i] != stop)
		s1[i] = s2[i];
	if (i >= n)
		return (NULL);
	s1[i] = s2[i];
	return (&s1[i + 1]);
}
