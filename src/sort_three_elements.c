/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:19:18 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/24 17:55:06 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else if (second > first && second > third)
		rra(a_list, 1);
	if (first > second)
		sa(a_list, 1);
}

t_data	*ft_lstlast(t_data *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_data *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}