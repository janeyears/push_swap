/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:57:08 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/25 16:41:57 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*return_best_node(t_data *b_list)
{
	if (b_list == NULL)
		return (NULL);
	while (b_list != NULL)
	{
		if (b_list->is_best_match == 1)
			return(b_list);
		b_list = b_list->next;
	}
	return (NULL);
}

static void	rotate_both(t_data **a, t_data **b, t_data *best, char c)
{
	while (*b != best && *a != best->pair)
	{
		if (c == 'u')
			rr(a, b);
		else
			rrr(a, b);
	}
}
static void	put_first(t_data **a, t_data **b, t_data *b_best, t_data *a_best)
{
	while (*a != a_best)
	{
		if (a_best->is_above_median == 1)
			ra(a, 1);
		else
			rra(a, 1);
	}
	while (*b != b_best)
	{
		if (b_best->is_above_median == 1)
			rb(b, 1);
		else
			rrb(b, 1);
	}
}

void push_back(t_data **a_list, t_data **b_list)
{
	t_data *best_node;

	best_node = return_best_node(*b_list);
	if (best_node == NULL)
		return ;
	if (best_node == *b_list && best_node->pair == *a_list) 
	{
		pa(a_list, b_list);
		return ;
	}
	if (best_node != *b_list && best_node->pair != *a_list)
	{
		if (best_node->is_above_median == best_node->pair->is_above_median)
		{
			if (best_node->is_above_median == 1)
				rotate_both(a_list, b_list, best_node, 'u');
		else
			rotate_both(a_list, b_list, best_node, 'd');
		}
	}
	put_first(a_list, b_list, best_node, best_node->pair);
	pa(a_list, b_list);
}
