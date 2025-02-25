/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:36:17 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/25 16:25:09 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doubly_lstadd_front(t_data **lst, t_data *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	if(*lst)
		(*lst)->previous = new;
	new->previous = NULL;
	*lst = new;
}

void	pa(t_data **a_list, t_data **b_list)
{
	t_data	*data_to_push;

	if(*b_list == NULL)
		return ;
	data_to_push = *b_list;
	*b_list = (*b_list)->next;
	doubly_lstadd_front(a_list, data_to_push);
	if (*b_list)
		(*b_list)->previous = NULL;
	ft_printf("pa\n");
}

void	pb(t_data **b_list, t_data **a_list)
{
	t_data	*data_to_push;

	if(*a_list == NULL)
		return ;
	data_to_push = *a_list;
	*a_list = (*a_list)->next;
	doubly_lstadd_front(b_list, data_to_push);
	if (*a_list)
		(*a_list)->previous = NULL;
	ft_printf("pb\n");
}
