/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:35:55 by ekashirs          #+#    #+#             */
/*   Updated: 2025/03/03 12:35:11 by ekashirs         ###   ########.fr       */
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
	ft_printf("sa\n");
}
