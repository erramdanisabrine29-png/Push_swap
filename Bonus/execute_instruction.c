/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saerramd <saerramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 12:03:18 by saerramd          #+#    #+#             */
/*   Updated: 2026/11/18 13:28:19 by saerramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_instruction(t_game *game, char *str)
{
	if (!checker_strcmp(str, "sa"))
		stack_swap(&game->a);
	else if (!checker_strcmp(str, "sb"))
		stack_swap(&game->b);
	else if (!checker_strcmp(str, "ss"))
	{
		stack_swap(&game->a);
		stack_swap(&game->b);
	}
	else if (!checker_strcmp(str, "pa"))
		stack_push(&game->b, &game->a);
	else if (!checker_strcmp(str, "pb"))
		stack_push(&game->a, &game->b);
	else if (!checker_strcmp(str, "ra"))
		stack_rotate(&game->a);
	else if (!checker_strcmp(str, "rb"))
		stack_rotate(&game->b);
	else if (!checker_strcmp(str, "rr"))
	{
		stack_rotate(&game->a);
		stack_rotate(&game->b);
	}
	else if (!checker_strcmp(str, "rra"))
		stack_reverse(&game->a);
	else if (!checker_strcmp(str, "rrb"))
		stack_reverse(&game->b);
	else if (!checker_strcmp(str, "rrr"))
	{
		stack_reverse(&game->a);
		stack_reverse(&game->b);
	}
}