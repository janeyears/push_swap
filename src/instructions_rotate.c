/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:11:25 by ekashirs          #+#    #+#             */
/*   Updated: 2025/03/03 12:43:58 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data **a_list, int print_flag)
{
	t_data	*first_node;
	t_data	*second_node;

	if (*a_list == NULL || (*a_list)->next == NULL)
		return ;
	first_node = *a_list;
	second_node = first_node->next;
	*a_list = second_node;
	first_node->next = NULL;
	ps_lstadd_back(a_list, first_node);
	if (print_flag)
		ft_printf("ra\n");
}

void	rb(t_data **b_list, int print_flag)
{
	t_data	*first_node;
	t_data	*second_node;

	if (*b_list == NULL || (*b_list)->next == NULL)
		return ;
	first_node = *b_list;
	second_node = first_node->next;
	*b_list = second_node;
	first_node->next = NULL;
	ps_lstadd_back(b_list, first_node);
	if (print_flag)
		ft_printf("rb\n");
}

void	rr(t_data **a_list, t_data **b_list)
{
	ra(a_list, 0);
	rb(b_list, 0);
	ft_printf("rr\n");
}
