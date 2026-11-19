#include "push_swap.h"

void	bench_text(char *text)
{
	int	length;

	length = 0;
	while (text[length])
		length++;
	write(2, text, length);
}

void	bench_number(t_count number)
{
	char	digit;

	if (number >= 10)
		bench_number(number / 10);
	digit = '0' + number % 10;
	write(2, &digit, 1);
}
