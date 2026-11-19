#include "push_swap.h"

static int	count_smaller(t_stack *a, int value)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < a->size)
	{
		if (a->values[i] < value)
			count++;
		i++;
	}
	return (count);
}

void	rank_values(t_game *game)
{
	int	*ranks;
	int	i;

	ranks = malloc(sizeof(int) * (size_t)game->a.size);
	if (!ranks)
		error_exit(game);
	i = 0;
	while (i < game->a.size)
	{
		ranks[i] = count_smaller(&game->a, game->a.values[i]);
		i++;
	}
	i = 0;
	while (i < game->a.size)
	{
		game->a.values[i] = ranks[i];
		i++;
	}
	free(ranks);
}
