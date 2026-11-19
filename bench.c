#include "push_swap.h"
static t_count	percentage_units(t_game *game)
{
	t_count	remainder;
	t_count	units;
	int		i;

	if (game->pairs == 0)
		return (0);
	remainder = 0;
	units = 0;
	i = 0;
	while (i++ < 10000)
	{
		remainder += game->inversions;
		units += remainder / game->pairs;
		remainder %= game->pairs;
	}
	if (remainder >= (game->pairs + 1) / 2)
		units++;
	return (units);
}

static void	print_disorder(t_game *game)
{
	t_count	units;

	units = percentage_units(game);
	bench_text("[bench] disorder: ");
	bench_number(units / 100);
	bench_text(".");
	if (units % 100 < 10)
		bench_text("0");
	bench_number(units % 100);
	bench_text("%\n");
}

static void	print_strategy(t_game *game)
{
	bench_text("[bench] strategy: ");
	if (game->requested == ADAPTIVE)
		bench_text("adaptive -> ");
	if (game->selected == SIMPLE)
		bench_text("simple O(n^2)\n");
	else if (game->selected == MEDIUM)
		bench_text("medium O(n*sqrt(n))\n");
	else
		bench_text("complex O(n*log(n))\n");
}

void	print_benchmark(t_game *game)
{
	int	i;

	print_disorder(game);
	print_strategy(game);
	bench_text("[bench] total: ");
	bench_number(game->total);
	bench_text("\n");
	i = 0;
	while (i < OP_COUNT)
	{
		bench_text("[bench] ");
		bench_text(operation_name(i));
		bench_text(": ");
		bench_number(game->counts[i]);
		bench_text("\n");
		i++;
	}
}
