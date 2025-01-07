/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:51:37 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/07 12:43:16 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	free_2darray(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*cur;

	if (NULL == stack)
		return ;
	cur = *stack;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*stack = NULL;
}

void	error_and_free(t_node **a, char **argv, bool flag_2_ac)
{
	free_stack(a);
	if (flag_2_ac)
		free_2darray(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *c)
{
	if (!(*c == '+' || *c == '-' || (*c >= '0' && *c <= '9')))
		return (1);
	if ((*c == '+' || *c == '-') && !(c[1] >= '0' && c[1] <= '9'))
		return (1);
	while (*++c)
	{
		if (!(*c >= '0' && *c <= '9'))
			return (1);
	}
	return (0);
}

int	check_duplicate(t_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
