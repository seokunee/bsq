#include "bsq.h"

void	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		ft_putchar(str[n++]);
}
