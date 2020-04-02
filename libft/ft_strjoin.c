/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_concat_two_str(char const *s1, char const *s2, char *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 != 0 && s1[j] != 0)
		result[i++] = s1[j++];
	j = 0;
	while (s2 != 0 && s2[j] != 0)
		result[i++] = s2[j++];
	result[i] = 0;
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		size;

	i = 0;
	while (s1 != 0 && s1[i] != 0)
		i = i + 1;
	size = i;
	i = 0;
	while (s2 != 0 && s2[i] != 0)
		i = i + 1;
	size = size + i;
	if ((result = (char *)malloc(size + 1)) == 0)
		return (0);
	ft_concat_two_str(s1, s2, result);
	return (result);
}
