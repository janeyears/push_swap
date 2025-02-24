/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:04:07 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/24 17:23:22 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

t_data	*return_smallest_node(t_data *a_list)
{
	t_data	*smallest_node;
	int	smallest_number;

	if (a_list == NULL)
		return (NULL);
	smallest_node = a_list;
	smallest_number = a_list->number;
	a_list = a_list->next;
	while(a_list != NULL)
	{
		if (a_list->number < smallest_number)
		{
			smallest_node = a_list;
			smallest_number = a_list->number;
		}
		a_list = a_list->next;
	}
	return(smallest_node);
}
void	check_median(t_data	*list, int median, int index)
{
	if (index <= median)
		list->is_above_median = 1;
	else
		list->is_above_median = 0;
}
void	assign_index(t_data *a_list, t_data *b_list)
{
	int	i;
	int	j;
	int	middle_a;
	int	middle_b;

	if (a_list == NULL || b_list == NULL)
		return ;
	i = 0;
	middle_a = ft_lstsize(a_list) / 2;
	while (a_list != NULL)
	{
		a_list->index = i;
		check_median(a_list, middle_a, i);
		i++;
		a_list = a_list->next;
	}
	j = 0;
	middle_b = ft_lstsize(b_list) / 2;
	while (b_list != NULL)
	{
		b_list->index = j;
		check_median(b_list, middle_b, j);
		j++;
		b_list = b_list->next;
	}
}
t_data	*return_best_pair(t_data *a_list, t_data *b_list)
{
	t_data	*pair;
	long	match;

	pair = NULL;
	match = LONG_MAX;

	while (a_list != NULL)
	{
		if (a_list->number > b_list->number && a_list->number < match)
		{
			match = a_list->number;
			pair = a_list;
		}
		a_list = a_list->next;
	}
	if (pair == NULL)
		pair = return_smallest_node(a_list);
	return(pair);
}
void	assign_pairs(t_data *a_list, t_data *b_list)
{
	t_data	*pair;
	if (a_list == NULL || b_list == NULL)
		return ;
	while (b_list != NULL)
	{
		pair = return_best_pair(a_list, b_list);
		b_list = b_list->next;
	}
}
