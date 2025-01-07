/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:17:03 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/07 12:46:31 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	push(t_node **dest, t_node **src)
{
	t_node	*pushing_node;

	if (NULL == *src)
		return ;
	pushing_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	pushing_node->prev = NULL;
	if (NULL == *dest)
	{
		*dest = pushing_node;
		pushing_node->next = NULL;
	}
	else
	{
		pushing_node->next = *dest;
		pushing_node->next->prev = pushing_node;
		*dest = pushing_node;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
