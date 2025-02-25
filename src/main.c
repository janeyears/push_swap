/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:40:30 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/25 13:17:23 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

static void	choose_sort_method(t_data **a_list)
{
	t_data	*b_list;

	b_list = NULL;
	if (ft_lstsize(*a_list) == 2)
		sa(a_list, 1);
	else if (ft_lstsize(*a_list) == 3)
		sort_three_elements(a_list);
	else
		sorting(a_list, &b_list);
}
int main(int ac, char **av)
{
	t_data *a_list;

	a_list = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit(1);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			error_and_exit();
		create_a_list(&a_list, av, ac);
	}
	else
		create_a_list(&a_list, av + 1, ac);
	if (is_list_sorted(a_list) == 1)
		choose_sort_method(&a_list);
	free_list(&a_list);
	return (0);
}
