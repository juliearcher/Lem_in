/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					get_path_len(t_node *path)
{
	t_node			*node;
	int				i;

	node = path;
	i = 1;
	while (node->hop_list != NULL)
	{
		node = node->hop_list->node;
		++i;
	}
	return (i);
}

static int		find_valid_children(t_lemin *data, int path)
{
	t_nodelist	*links;
	t_nodelist	*tmp;
	t_node		*parent;

	while (data->scan_infos.current != NULL)
	{
		parent = data->scan_infos.current->node;
		links = parent->connections;
		while (links != NULL)
		{
			if (valid_link(data, parent, links->node, path) &&
				update_child(data, parent, links->node, path) == FAILURE)
				return (FAILURE);
			links = links->next;
		}
		tmp = data->scan_infos.current;
		data->scan_infos.current = data->scan_infos.current->next;
		free(tmp);		
	}
	return (SUCCESS);
}

static int		find_new_path(t_lemin *data, int path)
{
	t_nodelist	*new;

	ft_bzero(&data->scan_infos, sizeof(t_scan));
	if ((new = create_new_link(data->start)) == NULL)
		return (FAILURE);
	new->next = NULL;
	data->scan_infos.next_depth = new;
	while ((data->scan_infos.current = data->scan_infos.next_depth) != NULL)
	{
		data->scan_infos.next_depth = NULL;
		if (find_valid_children(data, path) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	get_new_path(t_lemin *data)
{
	free_connections(data->output);
	data->output = NULL;
	data->start->last_visited = data->path;
	if (find_new_path(data, data->path) == FAILURE)
		return (FAILURE);
	ft_bzero(&data->scan_infos, sizeof(t_scan));
	choose_best_path(data, data->output);
	return (SUCCESS);
}

int			get_paths(t_lemin *data)
{
	data->path = 1;
	if (get_new_path(data) == FAILURE)
		return (FAILURE);
	while (data->output != NULL)
	{
		if (update_path_nodes(data) == FAILURE ||
			update_paths(data) == FAILURE)
			return (FAILURE);
		simulate(data);
		++data->path;
		get_new_path(data);
	}
	return (SUCCESS);
}
