#include "push_swap.h"
int	main(int argc, char **argv)
{
	t_game	game;
	int		count;

	if (argc == 1)
		return (0);
	init_game(&game);
	parse_options(&game, argc, argv);
	count = count_arguments(argc, argv);
	if (count < 0)
		error_exit(&game);
	if (count > 0)
	{
		allocate_stacks(&game, count);
		if (!fill_stack(&game.a, argc, argv) || has_duplicates(&game.a))
			error_exit(&game);
	}
	sort_game(&game);
	if (game.bench)
		print_benchmark(&game);
	free_game(&game);
	return (0);
}
