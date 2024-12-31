/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:17:25 by ekashirs          #+#    #+#             */
/*   Updated: 2024/12/31 13:22:40 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack_head)
{

	if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
		return ;
	*stack_head = (*stack_head)->next;
	(*stack_head)->prev->prev = *stack_head;
	(*stack_head)->prev->next = (*stack_head)->next;
	if ((*stack_head)->next)
		(*stack_head)->next->prev = (*stack_head)->prev;
	(*stack_head)->next = (*stack_head)->prev;
	(*stack_head)->prev = NULL;
}

void    sa(t_node **a)
{
	swap(a);
	write (1, "sa\n", 3);
}

void    sb(t_node **b)
{
	swap(b);
	write (1, "sb\n", 3);
}

void    ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write (1, "ss\n", 3);
}
