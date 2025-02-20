/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:01:15 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/20 17:27:35 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

void	error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
void	cleanup_split(char	**array, int i)
{
	int	j;

	j = -1;
	while(i < j)
	{
		free(array[j]);
		j++;
	}
	free(array - 1);
}

void	error_free_exit(t_data **a_list, char **av, int ac)
{
	free_list(a_list);
	if (ac == 2)
		cleanup_split(av);
	error_msg_and_exit();
}