#include "push_swap.h"

int	minimum_position(t_stack *stack)
{
	int	i;
	int	position;

	i = 1;
	position = 0;
	while (i < stack->size)
	{
		if (stack->values[i] < stack->values[position])
			position = i;
		i++;
	}
	return (position);
}

int	maximum_position(t_stack *stack)
{
	int	i;
	int	position;

	i = 1;
	position = 0;
	while (i < stack->size)
	{
		if (stack->values[i] > stack->values[position])
			position = i;
		i++;
	}
	return (position);
}

static void	rotate_side(t_game *game, int on_b, int reverse)
{
	if (on_b && reverse)
		rrb(game);
	else if (on_b)
		rb(game);
	else if (reverse)
		rra(game);
	else
		ra(game);
}

void	bring_to_top(t_game *game, int position, int on_b)
{
	int	size;
	int	rotations;
	int	reverse;

	size = game->a.size;
	if (on_b)
		size = game->b.size;
	reverse = (position > size / 2);
	rotations = position;
	if (reverse)
		rotations = size - position;
	while (rotations > 0)
	{
		rotate_side(game, on_b, reverse);
		rotations--;
	}
}
