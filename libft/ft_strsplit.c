/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_nb_of_words(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s != 0 && s[i] != 0)
	{
		while (s[i] == c)
			i = i + 1;
		if (s[i] == 0)
			break ;
		nb = nb + 1;
		while (s[i] != 0 && s[i] != c)
			i = i + 1;
	}
	return (nb);
}

static char	*copy_words(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i = i + 1;
	if ((str = (char *)malloc(i + 1)) == 0)
		return (0);
	i = -1;
	while (s[++i] != 0 && s[i] != c)
		str[i] = s[i];
	str[i] = 0;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size;
	int		i;

	size = get_nb_of_words(s, c);
	if (s == 0 || (tab = (char **)malloc((size + 1) * sizeof(char *))) == 0)
		return (0);
	size = 0;
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i = i + 1;
		if (s[i] == 0)
			break ;
		if ((tab[size] = copy_words(&s[i], c)) == 0)
			return (0);
		size = size + 1;
		while (s[i] != 0 && s[i] != c)
			i = i + 1;
	}
	tab[size] = 0;
	return (tab);
}

void		ft_free_tab(char **tab)
{
	int		i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		++i;
	}
	free(tab);
	tab = NULL;
}

int			ft_tablen(char **tab)
{
	int		i;

	if (tab == NULL)
		return (0);
	i = 0;
	while (tab[i] != 0)
		++i;
	return (i);
}
