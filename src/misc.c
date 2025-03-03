/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:19:18 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/28 10:59:05 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

long	ft_atol(const char *str, t_data **a_list, char **av, int ac)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (num > LONG_MAX / 10
			|| (num == LONG_MAX / 10 && (str[i] - '0') > LONG_MAX % 10))
			error_free_exit(a_list, av, ac);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	doubly_lstadd_front(t_data **lst, t_data *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	if (*lst)
		(*lst)->previous = new;
	new->previous = NULL;
	*lst = new;
}

void	doubly_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*last;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = NULL;
		(*lst)->previous = NULL;
	}
	else
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->previous = last;
		new->next = NULL;
	}
}
