/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:36:17 by ekashirs          #+#    #+#             */
/*   Updated: 2025/03/03 12:21:33 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data **a_list, t_data **b_list)
{
	t_data	*data_to_push;

	if (*b_list == NULL)
		return ;
	data_to_push = *b_list;
	*b_list = (*b_list)->next;
	ps_lstadd_front(a_list, data_to_push);
	ft_printf("pa\n");
}

void	pb(t_data **b_list, t_data **a_list)
{
	t_data	*data_to_push;

	if (*a_list == NULL)
		return ;
	data_to_push = *a_list;
	*a_list = (*a_list)->next;
	ps_lstadd_front(b_list, data_to_push);
	ft_printf("pb\n");
}
