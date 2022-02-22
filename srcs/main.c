#include "bsq.h"

int	g_n;

int	error(void)
{
	ft_putstr("Error\n");
	return (-1);
}

int	map_error(int n)
{
	write(2, "map error\n", 10);
	if (n != 1)
		write(1, "\n", 1);
	return (-1);
}

int	main(int ac, char **av)
{
	char	**strs;
	char	*value;

	g_n = 0;
	value = malloc(sizeof(char) * 3);
	if (!value)
		return (error());
	if (ac == 1)
	{
		strs = ft_split(ft_scanff(), '\n');
		if (strs != NULL && check_line(strs, value) && check_char(strs, value))
			ft_printing(&strs[1], value, 1);
		else
			map_error(1);
	}
	while (++g_n < ac)
	{
		strs = ft_parse(av[g_n], 0, 0, 0);
		if (strs != NULL && check_line(strs, value) && check_char(strs, value))
			ft_printing(&strs[1], value, ac - g_n);
		else
			map_error(ac - g_n);
	}
	return (0);
}
