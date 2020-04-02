/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

const char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	itemp;
	size_t	j;

	i = 0;
	if (needle[0] == 0)
		return (haystack);
	while (haystack[i] != 0 && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			itemp = i;
			while (needle[j] != 0 && haystack[itemp] != 0 &&
					haystack[itemp] == needle[j] && itemp < len)
			{
				itemp = itemp + 1;
				j = j + 1;
			}
			if (needle[j] == 0)
				return (&haystack[i]);
		}
		i = i + 1;
	}
	return (0);
}
