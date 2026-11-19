#include "push_swap.h"

void	sa(t_game *game)
{
	stack_swap(&game->a);
	emit(game, SA);
}

void	sb(t_game *game)
{
	stack_swap(&game->b);
	emit(game, SB);
}

void	ss(t_game *game)
{
	stack_swap(&game->a);
	stack_swap(&game->b);
	emit(game, SS);
}
