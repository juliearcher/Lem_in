#include "lemin.h"

t_path			*get_chosen_path(t_path *path_list, int path)
{
	t_path		*tmp;

	tmp = path_list;
	while (tmp != NULL)
	{
		if (tmp->path == path)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static t_node		*get_best_path(t_lemin *data)
{
	t_nodelist		*tmp;
	t_path			*path;
	t_node			*best_path;
	int				best_len;

	tmp = data->start->connections;
	best_len = -1;
	best_path = NULL;
	while (tmp != NULL)
	{
		path = get_chosen_path(tmp->node->path_list, data->path);
		if (path != NULL && (best_len < 0
				|| path->path_len + path->nb_ant < best_len))
		{
			best_path = tmp->node;
			best_len = path->path_len + path->nb_ant;
		}
		tmp = tmp->next;
	}
	return (best_path);
}

static int	determine_best_path(t_lemin *data)
{
	t_nodelist	*tmp;
	t_path		*path;
	int			nb_turns;
	int			res;

	tmp = data->start->connections;
	nb_turns = 0;
	while (tmp != NULL)
	{
		path = get_chosen_path(tmp->node->path_list, data->path);
		res = (path != NULL && path->nb_ant != 0 ?
			path->path_len + path->nb_ant - 1 : 0);
		if (res != 0 && (nb_turns == 0 || res > nb_turns))
			nb_turns = res;
		tmp = tmp->next;
	}
	return (nb_turns);
}

int			simulate(t_lemin *data)
{
	t_path		*path;
	int			ants;
	int			nb_turns;

	ants = data->nb_ants;
	while (ants != 0)
	{
		path = get_chosen_path(get_best_path(data)->path_list, data->path);
		++path->nb_ant;
		--ants;
	}
	nb_turns = determine_best_path(data);
	if (data->best_cost_path == 0 || nb_turns < data->best_cost_path)
	{
		data->best_path = data->path;
		data->best_cost_path = nb_turns;
	}
	return (SUCCESS);
}
