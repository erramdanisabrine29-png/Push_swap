#include "push_swap.h"
static int	read_digits(char **text, long limit, long *value)
{
	int	digit;

	if (**text < '0' || **text > '9')
		return (0);
	*value = 0;
	while (**text >= '0' && **text <= '9')
	{
		digit = **text - '0';
		if (*value > (limit - digit) / 10)
			return (0);
		*value = *value * 10 + digit;
		(*text)++;
	}
	return (**text == '\0' || is_space(**text));
}

static int	read_number(char **text, int *number)
{
	int		sign;
	long	value;
	long	limit;

	sign = 1;
	if (**text == '-' || **text == '+')
	{
		if (**text == '-')
			sign = -1;
		(*text)++;
	}
	limit = INT_MAX;
	if (sign == -1)
		limit++;
	if (!read_digits(text, limit, &value))
		return (0);
	*number = (int)(value * sign);
	return (1);
}

int	fill_stack(t_stack *a, int argc, char **argv)
{
	int		i;
	char	*text;

	i = 1;
	while (i < argc)
	{
		text = argv[i++];
		if (is_flag(text))
			continue ;
		while (*text)
		{
			while (is_space(*text))
				text++;
			if (!*text)
				break ;
			if (!read_number(&text, &a->values[a->size]))
				return (0);
			a->size++;
		}
	}
	return (1);
}
