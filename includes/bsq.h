#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_bsq
{
	int	x;
	int	y;
	int	size;
}				t_bsq;

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);
void	ft_putchar(const char letter);
char	**ft_split(char *str, char b);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_scanff(void);
int		ft_atoi(char *str);

/* ft_check.c */
int		check_char(char **strs, char *value);
int		check_line(char **strs, char *value);
int		ft_check_c(char *str);

/* ft_free.c */
void	free_int_arr(int **to_free, char **map);
void  free_char_arr(char **map);

/* ft_parse.c */
char	**ft_parse(char *filename, int cn_len, int fd, int len);
int	ft_strlen_content(const char *str, int n);
char	*ft_file_read(int fd, int size, int len);

/* ft_square.1.c*/
t_bsq	ft_solve(char **map, char *value);
int	find_min(int a, int b , int c);
void	check_square(int **fill, char **map);
void	fill_one_zero(int **fill, char **map, char *value);
void	ft_printing(char **map, char *value, int x);

/* ft_square.2.c*/
int		ft_map_width(char **map);
int		ft_map_height(char **map);
int		**create_map(int x, int y);

/* ft_square.3.c*/
int		**make_map(char **map, char*value);

/* ft_square.4.c*/
t_bsq	find_best(int **fill, char **map, int i, int j);
void	write_best(t_bsq *best, int **map, int i, int j);

#endif
