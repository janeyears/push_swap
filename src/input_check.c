/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:18:40 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/19 19:14:32 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"
#include <limits.h>

int	has_dupes(t_data *a_list, int nb)
{
	if (!a_list)
		return (0);
	while(a_list != NULL)
	{
		if (a_list->number == nb)
			return (1);
		a_list = a_list->next;
	}
	return (0);
}
int has_syntax_error(const char *str)
{
	if (!str || *str == '\0')
		return (1);
	if (*str == '+' || *str == '-')
	{
		if (*(str + 1) == '\0' || (*(str + 1) < '0' || *(str + 1) > '9'))
			return (1);
		str++;
	}
	else if (*str < '0' || *str > '9')
		return 1;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return 1;
		str++;
	}
	return (0);
}
int int_overflow_check(int value)
{
	if (value > INT_MAX || value < INT_MIN)
		return (1);
	else
		return (0);
}

int	 is_list_sorted(t_data *a_list)
{
	if (!a_list)
		return (1);
	while(a_list->next != NULL)
	{
		if(a_list->number > a_list->next->number)
			return (1);
		a_list = a_list->next;
	}
	return (0);
}
