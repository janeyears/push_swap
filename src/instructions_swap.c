/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:35:55 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/20 15:14:05 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

void	sa(t_data **a_list, int print_flag)
{
	t_data	*temp;

	if (*a_list == NULL || (*a_list)->next == NULL)
		return ;
	temp = *a_list;
	*a_list = (*a_list)->next;
	(*a_list)->next = temp;
	temp->previous = *a_list;
	if (temp->next)
		temp->next->previous = temp;
	(*a_list)->previous = NULL;
	if (print_flag)
		ft_printf("sa\n");
}

void	sb(t_data **b_list, int print_flag)
{
	t_data	*temp;

	if (*b_list == NULL || (*b_list)->next == NULL)
		return ;
	temp = *b_list;
	*b_list = (*b_list)->next;
	(*b_list)->next = temp;
	temp->previous = *b_list;
	if (temp->next)
		temp->next->previous = temp;
	(*b_list)->previous = NULL;
	if (print_flag)
		ft_printf("sb\n");
}

void	ss(t_data **a_list, t_data **b_list)
{
	sa(a_list, 0);
	sb(b_list, 0);
	ft_printf("ss\n");
}