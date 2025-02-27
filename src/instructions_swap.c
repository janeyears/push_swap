/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:35:55 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/27 14:38:29 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data **a_list)
{
	t_data	*temp;

	if (*a_list == NULL || (*a_list)->next == NULL)
		return ;
	temp = *a_list;
	*a_list = (*a_list)->next;
	temp->next = (*a_list)->next;
	(*a_list)->next = temp;
	(*a_list)->previous = NULL;
	if (temp->next != NULL)
		temp->next->previous = temp;
	temp->previous = *a_list;
	ft_printf("sa\n");
}
