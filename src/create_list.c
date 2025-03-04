/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:26:23 by ekashirs          #+#    #+#             */
/*   Updated: 2025/03/03 12:18:50 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	create_data_node(t_data **a_list, int value)
{
	t_data	*new_node;
	t_data	*last_node;

	if (!a_list)
		return (1);
	new_node = ft_calloc(1, sizeof(t_data));
	if (new_node == NULL)
		return (1);
	new_node->next = NULL;
	new_node->number = value;
	if (*a_list == NULL)
	{
		*a_list = new_node;
	}
	else
	{
		last_node = ft_lstlast(*a_list);
		last_node->next = new_node;
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
		if (has_syntax_error(av[i]))
			error_free_exit(a_list, av, ac);
		value = ft_atol(av[i], a_list, av, ac);
		if (int_overflow_check(value))
			error_free_exit(a_list, av, ac);
		int_value = (int)value;
		if (has_dupes(*a_list, int_value))
			error_free_exit(a_list, av, ac);
		if (create_data_node(a_list, int_value))
			error_free_exit(a_list, av, ac);
		i++;
	}
	if (ac == 2)
		cleanup_split(av);
}
