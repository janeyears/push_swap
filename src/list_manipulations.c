/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:04:07 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/25 18:39:20 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

t_data	*return_smallest_node(t_data *a_list)
{
	t_data	*smallest_node;
	int		smallest_number;

	if (a_list == NULL)
		return (NULL);
	smallest_node = a_list;
	smallest_number = a_list->number;
	a_list = a_list->next;
	while (a_list != NULL)
	{
		if (a_list->number < smallest_number)
		{
			smallest_node = a_list;
			smallest_number = a_list->number;
		}
		a_list = a_list->next;
	}
	return (smallest_node);
}

static void	indexing_list(t_data *list, int median)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = list;
	while (tmp != NULL)
	{
		tmp->index = i;
		if (i <= median)
			list->is_above_median = 1;
		else
			list->is_above_median = 0;
		i++;
		tmp = tmp->next;
    }
}
void	assign_index(t_data *a_list, t_data *b_list)
{
	int		middle_a;
	int		middle_b;

	if (a_list == NULL || b_list == NULL)
		return ;
	middle_a = ft_lstsize(a_list) / 2;
	middle_b = ft_lstsize(b_list) / 2;
	indexing_list(a_list, middle_a);
	indexing_list(b_list, middle_b);
}
t_data *return_best_pair(t_data *a_list, t_data *b_list)
{
	t_data	*pair;
	long	match;
	t_data	*tmp;

	pair = NULL;
	match = LONG_MAX;
	tmp = a_list; 

	while (tmp != NULL)
	{
		if (tmp->number > b_list->number && tmp->number < match)
		{
			match = tmp->number;
			pair = tmp;
		}
		tmp = tmp->next;
	}
	if (pair == NULL)
		pair = return_smallest_node(a_list);
	return (pair);
}
void	assign_pairs(t_data *a_list, t_data *b_list)
{
	t_data	*pair;
	if (a_list == NULL || b_list == NULL)
		return ;
	while (b_list != NULL)
	{
		pair = return_best_pair(a_list, b_list);
		b_list->pair = pair;
		b_list = b_list->next;
	}
}
