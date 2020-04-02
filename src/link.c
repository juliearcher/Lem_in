/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				add_new_link_end(t_lemin *data, t_node *node)
{
	t_nodelist	*new;
	t_nodelist	*tmp;

	if ((new = create_new_link(node)) == NULL)
		return (FAILURE);
	if (data->scan_infos.next_depth == NULL)
	{
		data->scan_infos.next_depth = new;
		data->scan_infos.next_depth_end = new;
		return (SUCCESS);
	}
	if (data->scan_infos.next_depth_end != NULL)
	{
		data->scan_infos.next_depth_end->next = new;
		data->scan_infos.next_depth_end = new;
		return (SUCCESS);
	}
	tmp = data->scan_infos.next_depth;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	data->scan_infos.next_depth_end = new;
	return (SUCCESS);
}

t_nodelist		*create_new_link(t_node *node)
{
	t_nodelist	*new;

	if ((new = (t_nodelist *)malloc(sizeof(t_nodelist))) == NULL)
		return (NULL);
	new->next = NULL;
	new->node = node;
	return (new);
}

static int		create_connection(t_node *first, t_node *second)
{
	t_nodelist	*new1;
	t_nodelist	*new2;
	t_nodelist	*tmp;

	tmp = first->connections;
	while (tmp != NULL && tmp->next != NULL && tmp->node != second)
		tmp = tmp->next;
	if (tmp != NULL && tmp->node == second)
		return (SUCCESS);
	if ((new1 = create_new_link(second)) == NULL ||
		(new2 = create_new_link(first)) == NULL)
		return (FAILURE);
	new1->next = first->connections;
	first->connections = new1;
	new2->next = second->connections;
	second->connections = new2;
	return (SUCCESS);
}

int				add_connection(t_lemin *data, char *line)
{
	t_node	*first;
	t_node	*second;
	char	*separator;
	char	temp;

	separator = line;
	while (separator != NULL && (separator = ft_strchr(separator, '-')) != 0)
	{
		temp = separator[0];
		separator[0] = 0;
		if ((first = get_node(data->anthill, line)) != NULL &&
			(second = get_node(data->anthill, &separator[1])) != NULL)
		{
			separator[0] = '-';
			return (create_connection(first, second));
		}
		separator[0] = temp;
		separator = &separator[1];
	}
	return (FAILURE);
}

void			free_connections(t_nodelist *connections)
{
	t_nodelist	*tmp;
	t_nodelist	*prev;

	tmp = connections;
	prev = NULL;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
	connections = NULL;
}
