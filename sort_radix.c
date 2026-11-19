#include "push_swap.h"

static int	count_bits(int maximum)
{
	int	bits;

	bits = 0;
	while (maximum > 0)
	{
		maximum = maximum >> 1;
		bits++;
	}
	return (bits);
}
static void	sort_one_bit(t_game *game, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((game->a.values[0] >> bit) & 1) == 0)
			pb(game);
		else
			ra(game);
		i++;
	}
	while (game->b.size > 0)
		pa(game);
}
void    sort_radix(t_game *game)
{
	int	bit;
	int	bits;
	int	size;

	size = game->a.size;
	bits = count_bits(size - 1);
	bit = 0;
	while (bit < bits)
	{
		sort_one_bit(game, bit, size);
		bit++;
	}
}
