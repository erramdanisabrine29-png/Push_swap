#include "push_swap.h"

char	*operation_name(t_operation op)
{
	char	*names[OP_COUNT];

	names[SA] = "sa";
	names[SB] = "sb";
	names[SS] = "ss";
	names[PA] = "pa";
	names[PB] = "pb";
	names[RA] = "ra";
	names[RB] = "rb";
	names[RR] = "rr";
	names[RRA] = "rra";
	names[RRB] = "rrb";
	names[RRR] = "rrr";
	return (names[op]);
}

void	emit(t_game *game, t_operation op)
{
	char	*name;
	int		length;

	name = operation_name(op);
	length = 0;
	while (name[length])
		length++;
	write(1, name, length);
	write(1, "\n", 1);
	game->counts[op]++;
	game->total++;
}
