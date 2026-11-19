/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saerramd <saerramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 00:00:00 by learner           #+#    #+#             */
/*   Updated: 2026/11/18 13:30:00 by saerramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned long long	t_count;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_operation;

typedef struct s_stack
{
	int	*values;
	int	size;
}	t_stack;

typedef struct s_game
{
	t_stack		a;
	t_stack		b;
	t_strategy	requested;
	t_strategy	selected;
	int			bench;
	t_count		inversions;
	t_count		pairs;
	t_count		total;
	t_count		counts[OP_COUNT];
}	t_game;

void		init_game(t_game *game);
int			is_space(char c);
int			is_flag(char *text);
void		parse_options(t_game *game, int argc, char **argv);
int			count_arguments(int argc, char **argv);
int			fill_stack(t_stack *a, int argc, char **argv);
int			has_duplicates(t_stack *a);
void		free_game(t_game *game);
void		error_exit(t_game *game);
void		allocate_stacks(t_game *game, int count);
int			is_sorted(t_stack *stack);
void		compute_disorder(t_game *game);
void		select_strategy(t_game *game);
void		sort_game(t_game *game);
void		rank_values(t_game *game);
void		stack_swap(t_stack *stack);
void		stack_push(t_stack *from, t_stack *to);
void		stack_rotate(t_stack *stack);
void		stack_reverse(t_stack *stack);
char		*operation_name(t_operation op);
void		emit(t_game *game, t_operation op);
void		sa(t_game *game);
void		sb(t_game *game);
void		ss(t_game *game);
void		pa(t_game *game);
void		pb(t_game *game);
void		ra(t_game *game);
void		rb(t_game *game);
void		rr(t_game *game);
void		rra(t_game *game);
void		rrb(t_game *game);
void		rrr(t_game *game);
int			minimum_position(t_stack *stack);
int			maximum_position(t_stack *stack);
void		bring_to_top(t_game *game, int position, int on_b);
void		sort_three(t_game *game);
void		sort_small(t_game *game);
void		sort_simple(t_game *game);
void		sort_medium(t_game *game);
void		sort_radix(t_game *game);
void		bench_text(char *text);
void		bench_number(t_count number);
void		print_benchmark(t_game *game);
int		check_instruction(char *str);
void	execute_instruction(t_game *game, char *str);
int		read_instructions(t_game *game);
void	checker_error(t_game *game);
void	checker_result(t_game *game);
int	checker_strcmp(char *s1, char *s2);
#endif
