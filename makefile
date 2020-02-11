SRCS	= dynarray.c dynarray_add.c \

OBJS	= ${SRCS:.c=.o}

NAME	= libdynarray.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror


${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}
	rm -f *.gch

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re
