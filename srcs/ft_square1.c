#include <bsq.h>

t_bsq	ft_solve(char **map, char *value)
{
	int		**int_map;
	t_bsq	best;

	best.size = 0;
	int_map = make_map(map, value);
	check_square(int_map, map);
	if (!int_map)
		return (best);
	best = find_best(int_map, map, -1 , -1);
	free_int_arr(int_map, map);
	return (best);
}

int	find_min(int a, int b , int c)
{
	int	min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

void	check_square(int **fill, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i] != 0)
	{
		j = -1;
		while (map[i][++j] != 0)
		{
			if (i == 0 && j == 0)
				;
			else if (i == 0 && j > 0)
				;
			else if (j == 0 && i > 0)
				;
			else if (fill[i - 1][j] != 0 && fill[i][j - 1] != 0 \
										&& fill[i - 1][j - 1] != 0 && fill[i][j] != 0)
			{
				fill[i][j] = find_min(fill[i - 1][j], fill[i][j - 1], fill[i - 1][j - 1]) + 1;
			}
		}
	}
}


void	fill_one_zero(int **fill, char **map, char *value)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i] != 0)
	{
		j = -1;
		while (map[i][++j] != 0)
		{
			if (map[i][j] == value[0] || map[i][j] == value[2])
				fill[i][j] = 1;
			else if (map[i][j] == value[1])
				fill[i][j] = 0;
		}
	}
}

void	ft_printing(char **map, char *value, int x)
{
	t_bsq	answer;
	int		i;
	int		j;

	i = -1;
	answer = ft_solve(map, value);
	while (++i < answer.size)
	{
		j = -1;
		while (++j < answer.size)
		{
			map[answer.x + i][answer.y + j] = value[2];
		}
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}
	if (x != 1)
			ft_putchar('\n');
	free_char_arr(map);
}