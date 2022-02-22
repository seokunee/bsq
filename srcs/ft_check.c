#include "bsq.h"

// 출력가능만 근데 우리가 읽는다는 것 어차피 출력이 된 것이기 때문에 빼줘도 돤다.

int	check_line(char **strs, char *value) // 지도의 언어를 저장한다.
{
	int	i;
	int	j;
	int	line;

	i = 0;
	j = -1;
	while (strs[0][i])
		i++;
	while (++j < i - 3)
		if (strs[0][j] < '0' || strs[0][j] > '9')
			return (0);
	value[0] = strs[0][j];
	value[1] = strs[0][j + 1];
	value[2] = strs[0][j + 2];
	strs[0][j] = '\0';
	if (value[0] == value[1] || value[0] == value[2] // 같은게 들어왔는지 확인
		|| value[1] == value[2])
		return (0);
	line = ft_atoi(strs[0]);
	i = 0;
	while (strs[i])
		i++;
	if (i - 1 != line || line == 0 || i <= 1)
		return (0);
	return (1);
}

int	check_char(char **strs, char *value) // 지도의 언어로만 이루어진 지도인지 확인
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (strs[i])
	{
		while (strs[i][j])
		{
			if (strs[i][j] != value[0] && strs[i][j] != value[1]
				&& strs[i][j] != value[2])
				return (0);
			j++;
		}
		if (j < 1)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check_c(char *str) // 
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i <= 1 || str[i - 1] != '\n')
		return (1);
	return (0);
}
