/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:01:15 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/19 19:03:55 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

void	error_msg_and_exit(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}
void	error_free_exit(char *msg, t_data **a_list, char **av, int ac)
{
	free_list(a_list);
	if (ac == 2)
		cleanup_2darr(av);
	error_msg_and_exit(msg);
}