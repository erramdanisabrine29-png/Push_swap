#include "push_swap.h"

void	pa(t_game *game)
{
	stack_push(&game->b, &game->a);
	emit(game, PA);
}

void	pb(t_game *game)
{
	stack_push(&game->a, &game->b);
	emit(game, PB);
}
