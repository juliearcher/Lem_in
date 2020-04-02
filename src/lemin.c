/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	init_lemin(t_lemin *data)
{
	data->input = NULL;
	data->input_end = NULL;
	data->anthill = NULL;
	data->start = NULL;
	data->end = NULL;
	data->scan_infos.next_depth = NULL;
	data->scan_infos.next_depth_end = NULL;
	data->scan_infos.current = NULL;
	data->output = NULL;
	data->nb_ants = 0;
	data->path = 0;
	data->best_path = 0;
	data->best_cost_path = 0;
	data->line_start = 1;
}

static void	free_lemin(t_lemin *data)
{
	t_input		*input_tmp;
	t_input		*input_old;
	
	free_nodes(data->anthill);
	input_tmp = data->input;
	while (input_tmp)
	{
		input_old = input_tmp;
		input_tmp = input_tmp->next;
		free(input_old->line);
		free(input_old);
	}
	if (data->scan_infos.current)
		free_connections(data->scan_infos.current);
	if (data->scan_infos.next_depth)
		free_connections(data->scan_infos.next_depth);
	if (data->output)
		free_connections(data->output);
	data->scan_infos.current = NULL;
	data->scan_infos.next_depth = NULL;
	data->scan_infos.next_depth_end = NULL;
	data->output = NULL;
}

int			start_lemin(void)
{
	t_lemin	data;

	init_lemin(&data);
	if (parse_map(&data) == FAILURE || !data.anthill || !data.start ||
		!data.end || !data.start->connections || !data.end->connections)
	{
		ft_putstr_fd("ERROR\n", 2);
		free_lemin(&data);
		return (FAILURE);
	}
	if (get_paths(&data) == FAILURE || data.best_path == 0)
	{
		ft_putstr_fd("ERROR\n", 2);
		free_lemin(&data);
		return (FAILURE);
	}
	print_input(data.input);
	start(&data);
	free_lemin(&data);
	return (SUCCESS);
}
