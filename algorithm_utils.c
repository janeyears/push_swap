#include "push_swap.h"

int stack_len(t_node *stack)
{
    int i;

    if (stack == NULL)
        return(0);
    i = 0;
    while(stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}
t_node	*return_cheapest(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}