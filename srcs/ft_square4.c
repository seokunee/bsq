#include <bsq.h>

void	write_best(t_bsq *best, int **map, int i, int j)
{
	best->x = i - map[i][j] + 1;
	best->y = j - map[i][j] + 1;
	best->size = map[i][j];
}

t_bsq	find_best(int **fill, char **map, int i, int j)
{
	t_bsq best;

	best.size = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (fill[i][j] > best.size)
				write_best(&best, fill, i, j);
			j++;
		}
		i++;
	}
	return (best);
}

