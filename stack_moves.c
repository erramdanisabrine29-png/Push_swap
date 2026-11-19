#include "push_swap.h"

void	stack_swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = temp;
}

void	stack_push(t_stack *from, t_stack *to)
{
	int	i;

	if (from->size == 0)
		return ;
	i = to->size;
	while (i > 0)
	{
		to->values[i] = to->values[i - 1];
		i--;
	}
	to->values[0] = from->values[0];
	to->size++;
	from->size--;
	i = 0;
	while (i < from->size)
	{
		from->values[i] = from->values[i + 1];
		i++;
	}
}

void	stack_rotate(t_stack *stack)
{
	int	first;
	int	i;

	if (stack->size < 2)
		return ;
	first = stack->values[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[stack->size - 1] = first;
}

void	stack_reverse(t_stack *stack)
{
	int	last;
	int	i;

	if (stack->size < 2)
		return ;
	last = stack->values[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = last;
}
