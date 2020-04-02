/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_node	*get_hop_node(t_lemin *data, t_nodelist *hop_list)
{
	t_nodelist			*tmp;

	tmp = hop_list;
	while (tmp != NULL)
	{
		if (tmp->path <= data->best_path)
			return (tmp->node);
		tmp = tmp->next;
	}
	return (NULL);
}

static int		move(t_lemin *data)
{
	t_nodelist		*tmp;
	t_node			*node;
	t_node			*dest;


	while (data->scan_infos.current)
	{
		node = data->scan_infos.current->node;
		dest = get_hop_node(data, node->hop_list);
		dest->ant = node->ant;
		if (dest != data->end && add_new_link_end(data, dest) == FAILURE)
			return(FAILURE);
		if (data->line_start == 0)
			ft_putchar(' ');
		ft_printf("L%d-%s", node->ant, dest->name);
		data->line_start = 0;
		tmp = data->scan_infos.current->next;
		free(data->scan_infos.current);
		data->scan_infos.current = tmp;
	}
	return (SUCCESS);
}

static int		first_turn(t_lemin *data, t_node *node, int nb)
{
	t_path		*path;

	path = get_chosen_path(node->path_list, data->best_path);
	if (path != NULL && path->nb_ant > 0 && path->sent < path->nb_ant)
	{
		++path->sent;
		node->ant = nb;
		if (node != data->end && add_new_link_end(data, node) == FAILURE)
			return (-1);
		if (data->line_start == 0)
			ft_putchar(' ');
		ft_printf("L%d-%s", node->ant, node->name);
		data->line_start = 0;
		return (SUCCESS);
	}
	return (FAILURE);
}

static int		do_first_turns(t_lemin *data, int *nb)
{
	t_nodelist *tmp;
	int			res;

	tmp = data->start->connections;
	while (tmp != NULL && data->nb_ants != 0)
	{
		if ((res = first_turn(data, tmp->node, *nb + 1)) == -1)
			return (FAILURE);
		else if (res == SUCCESS)
		{
			*nb = *nb + 1;
			--data->nb_ants;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int				start(t_lemin *data)
{
	int			nb;
	int			turn;

	ft_bzero((&data->scan_infos), sizeof(t_scan));
	nb = 0;
	turn = 1;
	while (!nb || ((data->scan_infos.current = data->scan_infos.next_depth) != NULL) || data->nb_ants != 0)
	{
		data->scan_infos.next_depth = NULL;
		if (move(data) == FAILURE)
			return (FAILURE);
		if (do_first_turns(data, &nb) == FAILURE)
			return (FAILURE);
		ft_putchar('\n');
		data->line_start = 1;
		++turn;
	}
	return (SUCCESS);
}
