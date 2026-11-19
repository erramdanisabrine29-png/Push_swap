#include "push_swap.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	count_words(char *text)
{
	int	count;

	count = 0;
	while (*text)
	{
		while (is_space(*text))
			text++;
		if (*text)
		{
			if (count == INT_MAX)
				return (-1);
			count++;
			while (*text && !is_space(*text))
				text++;
		}
	}
	return (count);
}

int	count_arguments(int argc, char **argv)
{
	int	i;
	int	words;
	int	total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			i++;
			continue ;
		}
		words = count_words(argv[i]);
		if (words < 1 || total > INT_MAX - words)
			return (-1);
		total += words;
		i++;
	}
	return (total);
}
