/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_to_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:57:27 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/28 11:30:36 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_node_position(t_data *a_list, t_data *node)
{
	int	pos;

	pos = 0;
	while (a_list)
	{
		if (a_list == node)
			return (pos);
		a_list = a_list->next;
		pos++;
	}
	return (-1);
}

void	sort_three_elements(t_data **a_list)
{
	if ((*a_list)->number > (*a_list)->next->number)
		sa(a_list);
	if ((*a_list)->next->number > (*a_list)->next->next->number)
	{
		rra(a_list, 1);
		if ((*a_list)->number > (*a_list)->next->number)
			sa(a_list);
	}
}

void	sort_four_elements(t_data **a_list, t_data **b_list)
{
	t_data	*smallest_node;
	int		pos;

	smallest_node = return_smallest_node(*a_list);
	pos = get_node_position(*a_list, smallest_node);
	if (pos == 1)
		ra(a_list, 1);
	else if (pos == 2)
	{
		ra(a_list, 1);
		ra(a_list, 1);
	}
	else if (pos == 3)
		rra(a_list, 1);
	else if (pos == -1)
		return ;
	pb(b_list, a_list);
	sort_three_elements(a_list);
	pa(a_list, b_list);
}

void	sort_five_elements(t_data **a_list, t_data **b_list)
{
	t_data	*smallest_node;
	int		pos;

	smallest_node = return_smallest_node(*a_list);
	pos = get_node_position(*a_list, smallest_node);
	if (pos == 1)
		ra(a_list, 1);
	else if (pos == 2)
	{
		ra(a_list, 1);
		ra(a_list, 1);
	}
	else if (pos == 3)
	{
		rra(a_list, 1);
		rra(a_list, 1);
	}
	else if (pos == 4)
		rra(a_list, 1);
	else if (pos == -1)
		return ;
	pb(b_list, a_list);
	sort_four_elements(a_list, b_list);
	pa(a_list, b_list);
}
