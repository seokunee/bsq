#include "bsq.h"

char	*ft_file_read(int fd, int size, int len) // 파일을 읽고 스트링으로 가져오는 아이
{
	char	buf[2048];
	char	*value;
	char	*tmp;

	value = malloc(sizeof(char)); // value의 역할 : 만약에 len 이 0 이 들어왔을 때, 반환할 메모리를 만들어줌.
	if (!value)
		return (NULL);
	len = read(fd, buf, 2048); // 파일 읽어서 buf에 저장
	while (len > 0)
	{
		tmp = malloc((size + len + 1) * sizeof(char)); // 읽은 만큼 메모리 할당 / 계속 만든다. 
		if (tmp == NULL)
			break ;
		tmp = ft_strncpy(tmp, value, size);
		free(value);
		ft_strncpy(tmp + size, buf, len);
		value = tmp;
		size += len;
		value[size] = '\0';
		len = read(fd, buf, 2048);
	}
	if (len)
		free(value);
	return (value);
}

int	ft_strlen_content(const char *str, int n)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (n == 1)
	{
		while (str[i] && str[i] <= '9' && str[i] >= '0')
			i++;
		return (i);
	}
	else if (n == 1)
	{
		while (str[k] && str[k] != ':')
			k++;
		k++;
		while (str[k] && str[k] == ' ')
			k++;
		while (str[k] && str[k + i] != '\n')
			i++;
		return (i);
	}
	return (i);
}

char	**ft_parse(char *filename, int cn_len, int fd, int len)
{
	char	*content;
	char	**dest;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		return (NULL);
	content = ft_file_read(fd, 0, 0);
	if (fd != STDIN_FILENO) //표준 입력을 의미한다.
		close(fd);
	while (content[cn_len])
		cn_len++;
	if (content[cn_len - 1] != '\n') // \n 으로 끝나야지 지도가 잘 마무리 된 것이기 때문이다.
		return (NULL);
	dest = ft_split(content, '\n');
	free(content); // 다 썼으니까 마무리
	cn_len = 0;
	if (dest[cn_len + 1])
		len = ft_strlen(dest[cn_len + 1]);
	else
		return (NULL);
	while (dest[++cn_len])
		if (len != ft_strlen(dest[cn_len])) // 모든 행의 길이가 같은지 확인
			return (NULL);
	return (dest);
}