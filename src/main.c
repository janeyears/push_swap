/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:40:30 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/20 17:20:39 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"
#include <unistd.h>

int main(int ac, char **av)
{
	t_data *a_list;
	t_data *b_list;

	a_list = NULL;
	b_list = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit(1);
	if (ac == 2)
		av = split_parser(av[1], ' ');
	if (av == NULL)
		error_and_exit();
	create_a_list(&a_list, av + 1, ac);
	if (is_list_sorted(a_list) == 0)
	{
		if (ft_lstsize(a_list) == 2)
			sa(&a_list, 1);
		else if (ft_lstsize(a_list) == 3)
			sort_three_elements(&a_list);
		else
			turk_algorithm(&a_list, &b_list);
	}
	free_list(&a_list);
	return (0);
}
