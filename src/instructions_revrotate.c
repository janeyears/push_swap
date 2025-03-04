/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_revrotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:50:12 by ekashirs          #+#    #+#             */
/*   Updated: 2025/03/03 12:43:29 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data **a_list, int print_flag)
{
	t_data	*data_to_rotate;
	t_data	*prev;

	if (*a_list == NULL || (*a_list)->next == NULL)
		return ;
	data_to_rotate = ft_lstlast(*a_list);
	prev = *a_list;
	while (prev->next != data_to_rotate)
		prev = prev->next;
	prev->next = NULL;
	ps_lstadd_front(a_list, data_to_rotate);
	if (print_flag)
		ft_printf("rra\n");
}

void	rrb(t_data **b_list, int print_flag)
{
	t_data	*data_to_rotate;
	t_data	*prev;

	if (*b_list == NULL || (*b_list)->next == NULL)
		return ;
	data_to_rotate = ft_lstlast(*b_list);
	prev = *b_list;
	while (prev->next != data_to_rotate)
		prev = prev->next;
	prev->next = NULL;
	ps_lstadd_front(b_list, data_to_rotate);
	if (print_flag)
		ft_printf("rrb\n");
}

void	rrr(t_data **a_list, t_data **b_list)
{
	rra(a_list, 0);
	rrb(b_list, 0);
	ft_printf("rrr\n");
}
