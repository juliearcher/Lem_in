/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

const char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	itemp;
	int	j;

	i = 0;
	if (needle[0] == 0)
		return (haystack);
	while (haystack[i] != 0)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			itemp = i;
			while (needle[j] != 0 && haystack[itemp] != 0 &&
					haystack[itemp] == needle[j])
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
