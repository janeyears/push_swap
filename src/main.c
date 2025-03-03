/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:40:30 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/28 11:40:55 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_sort_method(t_data **a_list)
{
	t_data	*b_list;

	b_list = NULL;
	if (ft_lstsize(*a_list) == 2)
		sa(a_list);
	else if (ft_lstsize(*a_list) == 3)
		sort_three_elements(a_list);
	else if (ft_lstsize(*a_list) == 4)
		sort_four_elements(a_list, &b_list);
	else if (ft_lstsize(*a_list) == 5)
		sort_five_elements(a_list, &b_list);
	else
		sorting(a_list, &b_list);
}

int	main(int ac, char **av)
{
	t_data	*a_list;

	a_list = NULL;
	if (ac == 1)
		exit(1);
	if (ac == 2 && !av[1][0])
		error_and_exit();
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL || av[0] == NULL)
		{
			free(av);
			error_and_exit();
		}
		create_a_list(&a_list, av, ac);
	}
	else
		create_a_list(&a_list, av + 1, ac);
	if (is_list_sorted(a_list) == 1)
		choose_sort_method(&a_list);
	free_list(&a_list);
	a_list = NULL;
	return (0);
}
