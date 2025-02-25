/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:26:06 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/25 18:28:38 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

static int	ret_steps(int position, int list_length, int above_median)
{
	if (above_median == 1)
		return(position);
	else
		return (list_length - position);
}

static void assign_best_move(t_data *b_list)
{
	t_data *best_node;
	long min_steps;

	if (b_list == NULL)
		return ;
	min_steps = LONG_MAX;
	best_node = NULL;
	while (b_list != NULL)
	{
		if (b_list->move_price < min_steps)
		{
			min_steps = b_list->move_price;
			best_node = b_list;
		}
		b_list = b_list->next;
	}
	if (best_node != NULL)
	{
		best_node->is_best_match = 1;
	}
}

void	calculate_steps_find_best(t_data *a_list, t_data *b_list)
{
	int	a_len;
	int	b_len;
	int	steps_in_b;
	int	steps_in_a;
	t_data	*original_b_list; 

	if (a_list == NULL || b_list == NULL)
		return ;
	a_len = ft_lstsize(a_list);
	b_len = ft_lstsize(b_list);
	original_b_list = b_list;  
	while (b_list != NULL)
	{
		steps_in_b = ret_steps(b_list->index, b_len, b_list->is_above_median);
		steps_in_a = ret_steps(b_list->pair->index, a_len, b_list->pair->is_above_median);
		b_list->move_price = steps_in_a + steps_in_b;
		b_list = b_list->next;
	}
	assign_best_move(original_b_list);
}
