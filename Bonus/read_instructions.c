/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saerramd <saerramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 12:03:33 by saerramd          #+#    #+#             */
/*   Updated: 2026/11/18 14:09:24 by saerramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	read_instructions(t_game *game)
{
	char	line[4];
	char	c;
	int		len;
	int		ret;

	len = 0;
	while (1)
	{
		ret = read(0, &c, 1);
		if (ret < 0)
			return (-1);
		if (ret == 0)
		{
			if (len == 0)
				return (1);
			line[len] = '\0';
			if (!check_instruction(line))
				return (0);
			execute_instruction(game, line);
			return (1);
		}
		if (c == '\n')
		{
			line[len] = '\0';
			if (!check_instruction(line))
				return (0);
			execute_instruction(game, line);
			len = 0;
		}
		else
		{
			if (len >= 3)
				return (0);
			line[len++] = c;
		}
	}
}