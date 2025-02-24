/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:17:00 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/24 17:51:51 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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

void	create_a_list(t_data **a_list, char **av, int ac);
void	calculate_steps_find_best(t_data *a_list, t_data *b_list);
void	error_and_exit(void);
void	cleanup_split(char	**array);
void	error_free_exit(t_data **a_list, char **av, int ac);
int		has_dupes(t_data *a_list, int nb);
int		has_syntax_error(const char *str);
int		int_overflow_check(int value);
int		is_list_sorted(t_data *a_list);
void	pb(t_data **b_list, t_data **a_list);
void	pa(t_data **a_list, t_data **b_list);
void	doubly_lstadd_front(t_data **lst, t_data *new);
void	rrr(t_data **a_list, t_data **b_list);
void	rrb(t_data **b_list, int print_flag);
void	rra(t_data **a_list, int print_flag);
void	rr(t_data **a_list, t_data **b_list);
void	rb(t_data **b_list, int print_flag);
void	ra(t_data **a_list, int print_flag);
void	ss(t_data **a_list, t_data **b_list);
void	sb(t_data **b_list, int print_flag);
void	sa(t_data **a_list, int print_flag);
void	assign_pairs(t_data *a_list, t_data *b_list);
t_data	*return_best_pair(t_data *a_list, t_data *b_list);
void	assign_index(t_data *a_list, t_data *b_list);
void	check_median(t_data	*list, int median, int index);
t_data	*return_smallest_node(t_data *a_list);
void	push_back(t_data **a_list, t_data **b_list);
t_data	*return_best_node(t_data *b_list);
void	sorting(t_data **a_list, t_data **b_list);
void	sort_three_elements(t_data **a_list);
char	**split_parser(char const *str, char separator);
int	ft_lstsize(t_data *lst);
t_data	*ft_lstlast(t_data *lst);
void	free_list(t_data **a_list);

#endif