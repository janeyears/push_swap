/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:26:23 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/24 18:07:01 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>


static int	create_data_node(t_data **a_list, int value)
{
	t_data	*new_node;
	t_data	*prev_node;

	if (!a_list)
		return (1);
	new_node = malloc(sizeof(t_data));
	if (new_node == NULL)
		return (1);
	new_node->next = NULL;
	new_node->number = value;
	if (*a_list == NULL)
	{
		*a_list = new_node;
		new_node->previous = NULL;
	}
	else
	{
		prev_node = ft_lstlast(*a_list);
		prev_node->next = new_node;
		new_node->previous = prev_node;
	}
	return (0);
}

void	create_a_list(t_data **a_list, char **av, int ac)
{
	long	value;
	int		int_value;
	int		i;

	i = 0;
	while (av[i] != NULL)
	{
		ft_printf("in the begining of create list\n");
		if (has_syntax_error(av[i]))
			error_free_exit(a_list, av, ac);
		ft_printf("after syntax check\n");
		value = atol(av[i]);
		ft_printf("after atol\n");
		if (int_overflow_check(value))
			error_free_exit(a_list, av, ac);
		ft_printf("after overflow check\n");
		int_value = (int)value;
		if (has_dupes(*a_list, int_value))
			error_free_exit(a_list, av, ac);
		ft_printf("after dupe check\n");
		if (create_data_node(a_list, int_value))
			error_free_exit(a_list, av, ac);
		ft_printf("after creating node\n");
		i++;
	}
	ft_printf("before free\n");
	if (ac == 2)
		cleanup_split(av);
	ft_printf("in the end of create list\n");
}
