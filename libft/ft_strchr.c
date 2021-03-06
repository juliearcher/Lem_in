/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

const char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s != 0 && s[i] != 0 && s[i] != c)
		i = i + 1;
	return (s[i] == c ? &s[i] : 0);
}
