/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		check_command(t_lemin *data, char *line, int *next)
{
	if (line[1] != '#')
		return (SUCCESS);
	if (ft_strcmp(line, "##start") == 0)
	{
		if (data->start != NULL || *next != NORMAL)
			return (FAILURE);
		*next = START;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (data->end != NULL || *next != NORMAL)
			return (FAILURE);
		*next = END;
	}
	return (SUCCESS);
}

static int		parse_line(t_lemin *data, char *line)
{
	static int	step = ROOM_DEC;
	static int	next = NORMAL;
	char		**tab;
	int			res;

	res = SUCCESS;
	if (line[0] == '#')
		return (check_command(data, line, &next));
	if (step == ROOM_DEC)
	{
		if ((tab = ft_strsplit(line, ' ')) == NULL)
			return (FAILURE);
		if (ft_tablen(tab) != 3)
			step = LINK_DEC;
		else
			res = add_new_room(data, tab, next);
		ft_free_tab(tab);
	}
	if (step == LINK_DEC)
		res = add_connection(data, line);
	next = NORMAL;
	return (res);
}

static t_input	*add_input_line(t_lemin *data, char *line)
{
	t_input *new;

	new = (t_input *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->line = line;
	new->next = NULL;
	if (data->input == NULL)
	{
		data->input = new;
		data->input_end = new;
		return (new);
	}
	data->input_end->next = new;
	data->input_end = new;
	return (data->input);
}

int				parse_map(t_lemin *data)
{
	char	*line;
	int		res;

	if ((res = get_next_line(0, &line) <= 0))
		return (FAILURE);
	if (!(data->input = add_input_line(data, line)))
		return (FAILURE);
	if (!ft_isnumber(line) || ft_atoi(line) < 1 || line[0] == '-')
		return (FAILURE);
	data->nb_ants = ft_atoi(line);
	while ((res = get_next_line(0, &line) > 0))
	{
		if (ft_strlen(line) == 0 || parse_line(data, line) == FAILURE)
		{
			free(line);
			break ;
		}
		else if (!(data->input = add_input_line(data, line)))
			return (FAILURE);
	}
	return (res < 0 ? FAILURE : SUCCESS);
}
