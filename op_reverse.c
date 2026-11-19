#include "push_swap.h"

void	rra(t_game *game)
{
	stack_reverse(&game->a);
	emit(game, RRA);
}

void	rrb(t_game *game)
{
	stack_reverse(&game->b);
	emit(game, RRB);
}

void	rrr(t_game *game)
{
	stack_reverse(&game->a);
	stack_reverse(&game->b);
	emit(game, RRR);
}
