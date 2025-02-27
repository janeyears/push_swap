/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_revrotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:50:12 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/27 15:06:36 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data **a_list, int print_flag)
{
	t_data	*data_to_rotate;

	if ((*a_list)->next == NULL || *a_list == NULL)
		return ;
	data_to_rotate = ft_lstlast(*a_list);
	if (data_to_rotate->previous)
		data_to_rotate->previous->next = NULL;
	doubly_lstadd_front(a_list, data_to_rotate);
	if (print_flag)
		ft_printf("rra\n");
}

void	rrb(t_data **b_list, int print_flag)
{
	t_data	*data_to_rotate;

	if ((*b_list)->next == NULL || *b_list == NULL)
		return ;
	data_to_rotate = ft_lstlast(*b_list);
	if (data_to_rotate->previous)
		data_to_rotate->previous->next = NULL;
	doubly_lstadd_front(b_list, data_to_rotate);
	if (print_flag)
		ft_printf("rrb\n");
}

void	rrr(t_data **a_list, t_data **b_list)
{
	rra(a_list, 0);
	rrb(b_list, 0);
	ft_printf("rrr\n");
}
