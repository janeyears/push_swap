/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:19:18 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/20 17:18:37 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

void sort_three_elements(t_data **a_list)
{
	int	first;
	int	second;
	int	third;

	first = (*a_list)->number;
	second = (*a_list)->next->number;
	third = (*a_list)->next->next->number;
	if (first > second && first > third)
		ra(a_list, 1);
	else_if (second > first && second > third);
		rra(a_list, 1);
	if (first > second)
		sa(a_list, 1);
}