/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:01:15 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/25 11:09:16 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

void	error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
void	cleanup_split(char	**array)
{
	int	i;

	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	error_free_exit(t_data **a_list, char **av, int ac)
{
	free_list(a_list);
	if (ac == 2)
		cleanup_split(av);
	error_and_exit();
}

void	free_list(t_data **a_list)
{
	t_data	*tmp;
	t_data	*cur;

	if (a_list == NULL || *a_list == NULL)
		return ;

	cur = *a_list;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*a_list = NULL;
}