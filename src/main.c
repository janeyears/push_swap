/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:40:30 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/24 18:13:52 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	choose_sort_method(t_data **a_list)
{
	t_data	*b_list;

	b_list = NULL;
	ft_printf("in the beginig of choose sorting\n");
	if (ft_lstsize(*a_list) == 2)
		sa(a_list, 1);
	else if (ft_lstsize(*a_list) == 3)
	{
		ft_printf("there are 3 elements\n");
		sort_three_elements(a_list);
	}
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
		av = split_parser(av[1], ' ');
	if (av == NULL)
		error_and_exit();
	create_a_list(&a_list, av + 1, ac);
	ft_printf("list is created\n");
	if (is_list_sorted(a_list) == 1)
		choose_sort_method(&a_list);
	free_list(&a_list);
	return (0);
}
