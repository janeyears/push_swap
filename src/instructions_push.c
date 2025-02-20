/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:36:17 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/20 17:30:02 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

static void	double_lstadd_front(t_data **lst, t_data *new)
{
	t_data	*temp;

	if (!new)
		return ;
	temp = *lst;
	new->next = temp;
	new->previous = NULL;
	if (temp)
		temp->previous = new;
	*lst = new;
}

void	pa(t_data **a_list, t_data **b_list)
{
	t_data	*data_to_push;

	if(*b_list == NULL)
		return ;
	data_to_push = *b_list;
	*b_list = (*b_list)->next;
	double_lstadd_front(a_list, data_to_push);
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
	double_lstadd_front(b_list, data_to_push);
	if (*a_list)
		(*a_list)->previous = NULL;
	ft_printf("pb\n");
}
