/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:17:19 by ekashirs          #+#    #+#             */
/*   Updated: 2024/12/31 13:09:26 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	reverse_rotate(t_node **stack)
{
	t_node	*last_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void    rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void    rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void    rrr(t_node **a, t_node **b)
{
    reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}