/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			update_child(t_lemin *data, t_node *parent,
				t_node *child, int path)
{
	t_nodelist	*new;

	if (child == data->end)
	{
		if ((new = create_new_link(parent)) == NULL)
			return (FAILURE);
		new->next = data->output;
		data->output = new;
	}
	else
	{
		child->last_visited = path;
		child->parent = parent;
	}
	if ((new = create_new_link(child)) == NULL)
		return (FAILURE);
	new->next = data->scan_infos.next_depth;
	data->scan_infos.next_depth = new;
	return (SUCCESS);
}

int			update_paths(t_lemin *data)
{
	t_nodelist	*hop;
	t_path		*new;
	t_node		*node;

	hop = data->start->hop_list;
	while (hop != NULL)
	{
		node = hop->node;
		if ((new = (t_path *)malloc(sizeof(t_path))) == NULL)
			return (FAILURE);
		new->path = data->path;
		new->path_len = get_path_len(node);
		new->nb_ant = 0;
		new->sent = 0;
		new->next = node->path_list;
		node->path_list = new;
		hop = hop->next;
	}
	return (SUCCESS);
}

static int	create_new_hop(t_lemin *data, t_node *node, t_node *next)
{
	t_nodelist	*new;

	if ((new = (t_nodelist *)malloc(sizeof(t_nodelist))) == NULL)
		return (FAILURE);
	new->path = data->path;
	if (next->hop_list != NULL && next->hop_list->node == node)
	{
		new->node = NULL;
		new->next = next->hop_list;
		next->hop_list = new;
	}
	else
	{
		new->node = next;
		new->next = node->hop_list;
		node->hop_list = new;
	}
	return (SUCCESS);
}

int			update_path_nodes(t_lemin *data)
{
	t_nodelist	*tmp;

	tmp = data->output;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (create_new_hop(data, tmp->node, tmp->next->node) == FAILURE)
			return (FAILURE);
		tmp = tmp->next;
	}
	return (SUCCESS);
}
