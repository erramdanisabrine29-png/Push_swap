#include "push_swap.h"

void	sort_simple(t_game *game)
{
	if (game->a.size <= 5)
	{
		sort_small(game); 
		return ;
	}
	while (game->a.size > 0)
	{
		bring_to_top(game, minimum_position(&game->a), 0);
		pb(game);
	}
	while (game->b.size > 0)
		pa(game);
}
