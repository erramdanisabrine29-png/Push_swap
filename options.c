/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learner <learner@student.42.fr>                                      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 00:00:00 by learner                                  */
/*   Updated: 2026/11/16 08:45:34 by waoukoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//compare 2 string if == return 1 if not return 0
static int	same_text(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a == *b);
}

//check if the text is a flag
int	is_flag(char *text)
{
	return (text[0] == '-' && text[1] == '-');
}

static int	strategy_flag(char *text)
{
	if (same_text(text, "--simple"))
		return (SIMPLE);
	if (same_text(text, "--medium"))
		return (MEDIUM);
	if (same_text(text, "--complex"))
		return (COMPLEX);
	if (same_text(text, "--adaptive"))
		return (ADAPTIVE);
	return (-1);
}

// same falg multiple time accepted , 2 different flag not accepted
void	parse_options(t_game *game, int argc, char **argv)
{
	int	i;
	int	choice;
	int	seen;

	i = 0;
	seen = -1;
	while (++i < argc)
	{
		if (same_text(argv[i], "--bench"))
			game->bench = 1;
		else if (is_flag(argv[i]))
		{
			choice = strategy_flag(argv[i]);
			if (choice < 0 || (seen >= 0 && seen != choice))
				error_exit(game);
			seen = choice;
			game->requested = choice;
		}
	}
}
