#include "push_swap.h"

void	init_game(t_game *game)
{
	int	i;

	game->a.values = NULL;
	game->b.values = NULL;
	game->a.size = 0;
	game->b.size = 0;
	game->requested = ADAPTIVE;
	game->selected = SIMPLE;
	game->bench = 0;
	game->inversions = 0;
	game->pairs = 0;
	game->total = 0;
	i = 0;
	while (i < OP_COUNT)
		game->counts[i++] = 0;
}

void	compute_disorder(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->a.size)
	{
		j = i + 1;
		while (j < game->a.size)
		{
			game->pairs++;
			if (game->a.values[i] > game->a.values[j])
				game->inversions++;
			j++;
		}
		i++;
	}
}

void	select_strategy(t_game *game)
{
	game->selected = game->requested;
	if (game->requested != ADAPTIVE)
		return ;
	if (game->pairs == 0 || game->inversions * 5 < game->pairs)
		game->selected = SIMPLE;
	else if (game->inversions * 2 < game->pairs)
		game->selected = MEDIUM;
	else
		game->selected = COMPLEX;
}

void	sort_game(t_game *game)
{
	compute_disorder(game);
	select_strategy(game);
	if (is_sorted(&game->a))
		return ;
	rank_values(game);
	if (game->selected == SIMPLE)
		sort_simple(game); 
	else if (game->selected == MEDIUM)
		sort_medium(game);
	else
		sort_radix(game);
}
