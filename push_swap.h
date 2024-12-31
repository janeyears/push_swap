/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:17:40 by ekashirs          #+#    #+#             */
/*   Updated: 2024/12/31 13:25:32 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				cur_position;
	int				final_index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//*** Error handling and free ***

void	free_2darray(char **argv);
void	free_stack(t_node **stack);
void	error_and_free(t_node **a, char **argv, bool flag_2_ac);
int	error_syntax(char *c);
int	check_duplicate(t_node *a, int nbr);

//*** Initializing a stack ***

void	init_a(t_node **a, char **argv, bool flag_2_ac);
void	create_node(t_node **stack, int nbr);
t_node	*ft_find_last(t_node *lst);

//*** Stacks moves ***

void    pa(t_node **a, t_node **b);
void    pb(t_node **b, t_node **a);
void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);
void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);
void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);

#endif