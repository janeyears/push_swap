#include "push_swap.h"

static void	rr_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	set_cur_position(*a);
	set_cur_position(*b);
}

static void	rrr_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
	set_cur_position (*a);
	set_cur_position(*b);
}

void	bring_to_top(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void move_nodes(t_node **a, t_node **b)
{
    t_node *cheapest;

    cheapest = return_cheapest(*b);
    if (cheapest->above_median && cheapest->target->above_median)
        rr_both(a, b, cheapest);
    else if (!(cheapest->above_median) && !(cheapest->target->above_median))
        rrr_both(a, b, cheapest);
    bring_to_top (b, cheapest, 'b');
    bring_to_top (a, cheapest->target, 'a');
    pa(a, b);
}

void    push_swap(t_node **a, t_node **b)
{
    t_node  *smallest;
    int len;

    len = stack_len(*a);
    if (len == 5)
        sort_five(a, b);
    else
    {
        while(len-- > 3)
            pb(b, a);
    }
    sort_three(a);
    while(*b)
    {
        set_nodes(*a, *b);
        move_nodes(a, b);
    }
	set_cur_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
