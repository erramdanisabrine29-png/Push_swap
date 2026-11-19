#include "push_swap.h"

void	free_game(t_game *game)
{
	free(game->a.values);
	free(game->b.values);
}

void	error_exit(t_game *game)
{
	free_game(game);
	write(2, "Error\n", 6);
	exit(1);
}

void	allocate_stacks(t_game *game, int count)
{
	game->a.size = 0;
	game->b.size = 0;
	game->a.values = malloc(sizeof(int) * (size_t)count);
	game->b.values = malloc(sizeof(int) * (size_t)count);
	if (!game->a.values || !game->b.values)
		error_exit(game);
}
