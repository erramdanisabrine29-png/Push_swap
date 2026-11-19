#include "push_swap.h"

static int	chunk_width(int size)
{
	int	width;

	width = 1;
	while ((long)width * width < size)
		width++;
	return (width);
}
static void	push_chunks(t_game *game, int width)
{
	int	limit;
	int	moved;
	int	size;

	size = game->a.size;
	limit = width;
	moved = 0;
	while (game->a.size > 0)
	{
		if (game->a.values[0] < limit)
		{
			pb(game);
			moved++;
		}
		else
			ra(game);
		if (moved == limit && limit < size)
		{
			if (size - limit < width)
                        {
				limit = size;
                        }
			else
				limit += width;
		}
	}
}
void	sort_medium(t_game *game)
{
	push_chunks(game, chunk_width(game->a.size));
	while (game->b.size > 0)
	{
		bring_to_top(game, maximum_position(&game->b), 1);
		pa(game);
	}
}
