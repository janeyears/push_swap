/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:17:10 by ekashirs          #+#    #+#             */
/*   Updated: 2024/12/31 12:58:56 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	rotate(t_node **stack)
{
	t_node	*last_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}	


void    ra(t_node **a)
{
	rotate(a);
	write (1, "ra\n",3);
}

void    rb(t_node **b)
{
	rotate(b);
	write (1, "rb\n", 3);
}

void    rr(t_node **a, t_node **b)
{
    rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}