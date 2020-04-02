/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup_until(const char *s1, const char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (s1[i] != 0 && s1[i] != c)
		i = i + 1;
	if ((dest = (char *)malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != 0 && s1[i] != c)
	{
		dest[i] = s1[i];
		i = i + 1;
	}
	dest[i] = 0;
	return (dest);
}
