/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:17:00 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/21 17:56:48 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdbool.h>

typedef struct s_data
{
	int				number;
	int				move_price;	
	int				index;
	int			is_above_median;
	int			is_best_match;
	struct s_data	*pair;
	struct s_data	*previous;
	struct s_data	*next;
}	t_data;

#endif