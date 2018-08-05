#include <stdio.h>

int	main(int ac, char **av)
{
	char	*base = "0123456789abcdef";

	if (ac == 2)
		printf("%d", (av[1][0] - 'a' + 1) % 5);
	return (0);
}
