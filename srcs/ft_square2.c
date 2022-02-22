#include <bsq.h>

int	ft_map_width(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	**create_map(int h, int w)
{
	int	i;
	int	**map;

	i = 0;
	map = (int **)malloc(sizeof(int *) * h);
	if (!map)
		return (0);
	while (i < w)
	{
		map[i] = (int *)malloc(sizeof(int) * w);
		i++;
	}
	return (map);
}
