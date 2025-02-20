/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_revrotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:50:12 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/20 17:15:48 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

static void	doubly_lstadd_front(t_data **lst, t_data *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	if(*lst)
		(*lst)->previous = new;
	new->previous = NULL;
	*lst = new;
}

void	rra(t_data **a_list, int print_flag)
{
	t_data	*last_node;

	if ((*a_list)->next == NULL || *a_list == NULL)
		return ;
	last_node = ft_lstlast(*a_list);
	if (last_node->previous)
		last_node->previous->next = NULL;
	doubly_lstadd_front(a_list, last_node);
	if (print_flag)
		ft_printf("rra\n");
}

void	rrb(t_data **b_list, int print_flag)
{
	t_data	*last_node;

	if ((*b_list)->next == NULL || *b_list == NULL)
		return ;
	last_node = ft_lstlast(*b_list);
	if (last_node->previous)
		last_node->previous->next = NULL;
	doubly_lstadd_front(b_list, last_node);
	if (print_flag)
		ft_printf("rrb\n");
}

void	rrr(t_data **a_list, t_data **b_list)
{
	rra(a_list, 0);
	rrb(b_list, 0);
	ft_printf("rrr\n");
}