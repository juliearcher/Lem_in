/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

int			get_line_end(char **full_line, int size)
{
	char	*tmp;
	char	*str;
	size_t	i;

	if (size == -1)
		return (-1);
	else if (size == 0 && *full_line == 0)
		return (0);
	str = ft_strchr(*full_line, '\n');
	i = str == 0 ? (int)ft_strlen(*full_line) - 1 : str - *full_line;
	if (i == ft_strlen(*full_line) - 1)
	{
		free(*full_line);
		*full_line = 0;
		return (1);
	}
	tmp = ft_strdup(str + 1);
	free(*full_line);
	*full_line = tmp;
	return (tmp == NULL ? -1 : 1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*full_line = 0;
	char			*tmp;
	char			tab[BUFF_SIZE + 1];
	int				size;

	if (BUFF_SIZE <= 0)
		return (-1);
	while ((size = read(fd, tab, BUFF_SIZE)) > 0)
	{
		tab[size] = 0;
		tmp = ft_strjoin(full_line, tab);
		if (full_line != 0)
			free(full_line);
		full_line = tmp;
		if (ft_strchr(full_line, '\n'))
			break ;
	}
	if (size == -1 || (size == 0 && full_line == 0))
		return (get_line_end(&full_line, size));
	*line = ft_strdup_until(full_line, '\n');
	return (get_line_end(&full_line, size));
}
