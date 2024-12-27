/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:33:06 by ekashirs          #+#    #+#             */
/*   Updated: 2024/12/27 16:25:17 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_last(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	create_node(t_node **stack, int nbr)
{
	t_node	*new_node;
	t_node	*last_node;
	
	if (stack == NULL)
		return ;
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->value = nbr;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else 
	{
		last_node = ft_find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_a(t_node **a, char **argv, bool flag_2_ac)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_and_free(a, argv, flag_2_ac);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_and_free (a, argv, flag_2_ac);
		if (check_dublicate (*a, (int)nbr))
			error_and_free (a, argv, flag_2_ac);
		create_node(a, (int)nbr);
		i++;
	}
	if (flag_2_ac)
		free_2darray(argv);
}
