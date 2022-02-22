SOURCE	= srcs/
SRCS    = main.c ft_atoi.c ft_parse.c ft_putchar.c ft_putstr.c \
		  ft_square4.c ft_strlen.c ft_split.c ft_strncpy.c ft_free.c\
		  ft_check.c ft_square1.c ft_square2.c ft_scanff.c ft_square3.c
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
HEAD	= includes
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME    = bsq
NORMINETTE = norminette
NORMOBJS	= ${addprefix ${SOURCE},${SRCS}}

.c.o:
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc ${CFLAGS} $^ -o $@

all :		${NAME}

clean:
			rm -f ${OBJS}

fclean:
			rm -f ${OBJS}
			rm -f ${NAME}

norm:
			${NORMINETTE} ${NORMOBJS}

re:			fclean all clean

.PHONY:		all clean fclean re norm
