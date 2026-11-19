/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saerramd <saerramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:03:46 by saerramd          #+#    #+#             */
/*   Updated: 2026/11/18 13:25:59 by saerramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	check_instruction(char *str)
{
	if (!str)
		return (0);
	if (!checker_strcmp(str, "sa") || !checker_strcmp(str, "sb")
		|| !checker_strcmp(str, "ss") || !checker_strcmp(str, "pa")
		|| !checker_strcmp(str, "pb") || !checker_strcmp(str, "ra")
		|| !checker_strcmp(str, "rb") || !checker_strcmp(str, "rr")
		|| !checker_strcmp(str, "rra") || !checker_strcmp(str, "rrb")
		|| !checker_strcmp(str, "rrr"))
		return (1);
	return (0);
}
