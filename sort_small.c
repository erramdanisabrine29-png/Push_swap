#include "push_swap.h"
void	sort_three(t_game *game)
{
	int	*a;

	a = game->a.values;
	if (a[0] > a[1] && a[0] > a[2])
		ra(game);
	else if (a[1] > a[0] && a[1] > a[2])
		rra(game);
	if (a[0] > a[1])
		sa(game);
}

void	sort_small(t_game *game)
{
	if (game->a.size == 2)
	{
		if (!is_sorted(&game->a))
			sa(game);
		return ;
	}
	while (game->a.size > 3)
	{
		bring_to_top(game, minimum_position(&game->a), 0);
		pb(game);
	}
	if (game->a.size == 3)
		sort_three(game);
	while (game->b.size > 0)
		pa(game);
}
