/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:57:42 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/09 13:45:31 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	set_cur_position(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->cur_position = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_node(t_node *a, t_node *b)
{
	t_node	*cur_a;
	t_node	*target;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->value > b->value && cur_a->value < best_match)
			{
				best_match = cur_a->value;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_cost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->cost = b->cur_position;
		if (!(b->above_median))
			b->cost = len_b - b->cur_position;
		if (b->target->above_median)
			b->cost += b->target->cur_position;
		else
			b->cost += len_a - (b->target->cur_position);
		b = b->next;
	}
}

void	set_cheapest(t_node *b)
{
	long	best_match;
	t_node	*best_match_node;

	if (b == NULL)
		return ;
	best_match = LONG_MAX;
	while (b)
	{
		if (b-> cost < best_match)
		{
			best_match = b->cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	set_nodes(t_node *a, t_node *b)
{
	set_cur_position(a);
	set_cur_position(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
