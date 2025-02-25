/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:11:48 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/25 13:16:51 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_instructions(t_data **a_list, t_data *smallest_number)
{
	if (smallest_number->is_above_median == 0)
	{
		while(*a_list != smallest_number)
			rra(a_list, 1);
	}
	else
	{
		while(*a_list != smallest_number)
			ra(a_list, 1);
	}
}

static void	finish_sorting(t_data **a_list)
{
	t_data	*smallest_number;
	
	smallest_number = return_smallest_node(*a_list);
	choose_instructions(a_list, smallest_number);
}

void	sorting(t_data **a_list, t_data **b_list)
{
	while(ft_lstsize(*a_list) != 3)
		pb(b_list, a_list);
	sort_three_elements(a_list);
	while(*b_list)
	{
		assign_index(*a_list, *b_list);
		assign_pairs(*a_list, *b_list);
		calculate_steps_find_best(*a_list, *b_list);
		push_back(a_list, b_list);
	}
	finish_sorting(a_list);
}
