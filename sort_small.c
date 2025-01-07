/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:57:50 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/07 16:19:46 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

bool	sorted(t_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_node	*find_biggest(t_node *stack)
{
	int		biggest;
	t_node	*biggest_node;

	if (stack == NULL)
		return (NULL);
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->value > biggest)
		{
			biggest = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	sort_three(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_biggest(*a);
	if (*a == biggest_node)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_five(t_node **a, t_node **b)
{
	while (stack_len(*a) > 3)
	{
		set_nodes(*a, *b);
		bring_to_top(a, find_smallest(*a), 'a');
		pb(b, a);
	}
}
