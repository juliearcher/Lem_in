/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_node			*get_node(t_node *anthill, char *name)
{
	if (name == NULL)
		return (NULL);
	while (anthill != NULL && ft_strcmp(anthill->name, name) != 0)
		anthill = anthill->next;
	return (anthill);
}

static t_node	*create_new_node(char *name, int x, int y)
{
	t_node	*new;

	if ((new = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	new->next = NULL;
	new->connections = NULL;
	new->hop_list = NULL;
	new->path_list = NULL;
	if ((new->name = ft_strdup(name)) == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->ant = 0;
	new->last_visited = 0;
	new->already_in_path = 0;
	new->parent = NULL;
	new->value = 0;
	return (new);
}

static t_node	*last_valid_node(t_lemin *data, char *name, int x, int y)
{
	t_node	*tmp;

	tmp = data->anthill;
	while (tmp != NULL && tmp->next != NULL &&
		ft_strcmp(tmp->name, name) != 0 && (tmp->x != x || tmp->y != y))
		tmp = tmp->next;
	return (tmp);
}

int				add_new_room(t_lemin *data, char **tab, int next)
{
	t_node	*tmp;
	t_node	*elem;
	int		x;
	int		y;

	x = ft_atoi(tab[1]);
	y = ft_atoi(tab[2]);
	if (tab[0][0] == 'L' || !ft_isnumber(tab[1]) || !ft_isnumber(tab[2]))
		return (FAILURE);
	tmp = last_valid_node(data, tab[0], x, y);
	if (tmp != NULL && (ft_strcmp(tmp->name, tab[0]) == 0 ||
			(tmp->x == x && tmp->y == y)))
		return (FAILURE);
	if ((elem = create_new_node(tab[0], x, y)) == NULL)
		return (FAILURE);
	if (tmp == NULL)
		data->anthill = elem;
	else
		tmp->next = elem;
	if (next == START)
		data->start = elem;
	else if (next == END)
		data->end = elem;
	return (SUCCESS);
}

void			free_nodes(t_node *anthill)
{
	t_node	*tmp;
	t_node	*prev;
	t_path	*tmp_path;
	t_path	*prev_path;

	tmp = anthill;
	prev = NULL;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		free_connections(prev->connections);
		free_connections(prev->hop_list);
		tmp_path = prev->path_list;
		prev_path = NULL;
		while (tmp_path != NULL)
		{
			prev_path = tmp_path;
			tmp_path = tmp_path->next;
			free(prev_path);
		}
		free(prev->name);
		free(prev);
	}
	anthill = NULL;
}
