/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:14:34 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 01:14:36 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	get_path_depth(t_node *path)
{
	t_node	*tmp;
	int		value;

	value = 1;
	tmp = path;
	while (tmp != NULL && tmp->parent != NULL)
	{
		value += tmp->hop_list != NULL && tmp->hop_list->node == tmp->parent ? -1 : 1;
		tmp = tmp->parent;
	}
	return (value);
}

static int	create_path(t_lemin *data, t_node *best_path)
{
	t_nodelist	*new;
	t_node		*node;

	if (best_path == NULL)
		return (SUCCESS);
	free_connections(data->output);
	if ((new = create_new_link(data->end)) == NULL)
		return (FAILURE);
	new->next = NULL;
	data->output = new;
	node = best_path;
	while (node != NULL)
	{
		if ((new = create_new_link(node)) == NULL)
			return (FAILURE);
		new->next = data->output;
		data->output = new;
		node = node->parent;
	}
	return (SUCCESS);
}

int			choose_best_path(t_lemin *data, t_nodelist *output)
{
	t_node	*best_path;
	int		current;
	int		best;

	best_path = NULL;
	best = 0;
	while (output != NULL)
	{
		current = get_path_depth(output->node);
		if (best == 0 || current < best)
		{
			best = current;
			best_path = output->node;
		}
		output = output->next;
	}
	return (create_path(data, best_path));
}