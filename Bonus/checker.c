/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saerramd <saerramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 12:02:50 by saerramd          #+#    #+#             */
/*   Updated: 2026/11/19 10:59:27 by saerramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		count;
	int		ret;

	if (argc == 1)
		return (0);
	init_game(&game);
	count = count_arguments(argc, argv);
	if (count <= 0)
		error_exit(&game);
	allocate_stacks(&game, count);
	if (!fill_stack(&game.a, argc, argv) || has_duplicates(&game.a))
		error_exit(&game);
	ret = read_instructions(&game);
	if (ret != 1)
		error_exit(&game);
	checker_result(&game);
	free_game(&game);
	return (0);
}
