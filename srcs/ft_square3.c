#include <bsq.h>

int	**make_map(char **map, char *value)
{
	int	h_max;
	int	w_max;
	int	**map_arr;

	h_max =  ft_map_height(map); 
	w_max = ft_map_width(map); 
	map_arr = create_map(h_max, w_max);
	if (!map_arr)
		return (0);
	fill_one_zero(map_arr, map, value);
	return (map_arr);
}