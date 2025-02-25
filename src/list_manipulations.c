/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:04:07 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/25 13:11:51 by ekashirs         ###   ########.fr       */
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
void	check_median(t_data	*list, int median, int index)
{
	if (index <= median)
	{
		list->is_above_median = 1;
	}
		
	else
		list->is_above_median = 0;
}
void	assign_index(t_data *a_list, t_data *b_list)
{
	int		i;
	int		j;
	int		middle_a;
	int		middle_b;
	t_data	*tmp_a;
	t_data	*tmp_b;

	if (a_list == NULL || b_list == NULL)
		return ;
	tmp_a = a_list;
	tmp_b = b_list;
	middle_a = ft_lstsize(a_list) / 2;
	middle_b = ft_lstsize(b_list) / 2;
	i = 0;
	while (tmp_a != NULL)
	{
		tmp_a->index = i; 
		check_median(tmp_a, middle_a, i);
		i++;
		tmp_a = tmp_a->next;
	}
	j = 0;
	while (tmp_b != NULL)
	{
		tmp_b->index = j;
		check_median(tmp_b, middle_b, j);
		j++;
		tmp_b = tmp_b->next;
	}
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
