#include "push_swap.h"

void	ra(t_game *game)
{
	stack_rotate(&game->a);
	emit(game, RA);
}

void	rb(t_game *game)
{
	stack_rotate(&game->b);
	emit(game, RB);
}

void	rr(t_game *game)
{
	stack_rotate(&game->a);
	stack_rotate(&game->b);
	emit(game, RR);
}
