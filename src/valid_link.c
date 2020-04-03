/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	valid_already_in_path(t_lemin *data, t_node *parent,
				t_node *child, int path)
{
	t_nodelist	*parent_data;
	t_nodelist	*child_data;

	parent_data = parent->hop_list;
	child_data = child->hop_list;
	if (parent->already_in_path == path)
	{
		if (child_data != NULL && child_data->node == parent)
			child->already_in_path = path;
		return (1);
	}
	if (child_data != NULL && child_data->node == parent)
	{
		child->already_in_path = path;
		return (1);
	}
	if (parent_data != NULL && parent_data->node != NULL)
	{
		if (parent == data->start && (child_data == NULL ||
				child_data->node == NULL))
			return (1);
		return (0);
	}
	return (1);
}

int			valid_link(t_lemin *data, t_node *parent, t_node *child, int path)
{
	if (child->last_visited == path ||
		child == data->start || parent == data->end)
		return (0);
	if (parent == data->start && child == data->end)
	{
		if (child->parent == NULL)
			child->parent = parent;
		else
			return (0);
	}
	return (valid_already_in_path(data, parent, child, path));
}
