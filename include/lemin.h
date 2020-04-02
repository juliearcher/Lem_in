/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarcher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:38:04 by jarcher           #+#    #+#             */
/*   Updated: 2020/02/24 00:38:07 by jarcher          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/*
** e_type == node_type
** e_step == parsing step (ants nb -> room declaration -> links declaration)
*/
enum			e_type
{
	NORMAL,
	START,
	END
};

enum			e_step
{
	ROOM_DEC,
	LINK_DEC
};

enum			e_error
{
	SUCCESS,
	FAILURE
};

typedef struct	s_input
{
	struct s_input	*next;
	char			*line;
}				t_input;

struct s_node;

typedef struct		s_path
{
	struct s_path	*next;
	int				path;
	int				path_len;
	int				nb_ant;
	int				sent;
}					t_path;

typedef struct	s_nodelist
{
	struct s_nodelist	*next;
	int					path;
	struct s_node		*node;
}				t_nodelist;

typedef struct			s_node
{
	struct s_node		*next;
	t_nodelist			*connections;
	t_nodelist			*hop_list;
	t_path				*path_list;
	char				*name;
	int					x;
	int					y;
	int					ant;
	int					last_visited;
	int					already_in_path;
	struct s_node		*parent;
	int					value;
}						t_node;

typedef struct		s_scan
{
	t_nodelist		*current;
	t_nodelist		*next_depth;
	t_nodelist		*next_depth_end;
}					t_scan;

typedef struct	s_lemin
{
	t_input		*input;
	t_input		*input_end;
	t_node		*anthill;
	t_node		*start;
	t_node		*end;
	t_scan		scan_infos;
	t_nodelist	*output;
	int			nb_ants;
	int			path;
	int			best_path;
	int			best_cost_path;
	int			line_start;
}				t_lemin;

/*
** ants.c
*/
int				start(t_lemin *data);

/*
** input.c
*/
void			print_input(t_input *input);

/*
** lemin.c
*/
int				start_lemin(void);

/*
** link.c
*/
int				add_new_link_end(t_lemin *data, t_node *node);
t_nodelist		*create_new_link(t_node *node);
int				add_connection(t_lemin *data, char *line);
void			free_connections(t_nodelist *connections);

/*
** node.c
*/
t_node			*get_node(t_node *anthill, char *name);
int				add_new_room(t_lemin *data, char **tab, int next);
void			free_nodes(t_node *anthill);

/*
** parser.c
*/
int				parse_map(t_lemin *data);

/*
**path.c
*/
int				choose_best_path(t_lemin *data, t_nodelist *output);

/*
** scan.c
*/
int				get_path_len(t_node *path);
int				get_paths(t_lemin *data);

/*
** simulation.c
*/
t_path			*get_chosen_path(t_path *path_list, int path);
int				simulate(t_lemin *data);

/*
** update_path.c
*/
int 			update_child(t_lemin *data, t_node *parent, t_node *child, int path);
int				update_paths(t_lemin *data);
int				update_path_nodes(t_lemin *data);

/*
** valid_link.c
*/
int				valid_link(t_lemin *data, t_node *parent, t_node *child, int path);

#endif
