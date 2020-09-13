HDRS	= dynarray.h \

SRCS	= dynarray.c dynarray_add.c \

OBJS	= ${SRCS:.c=.o}

NAME	= libdynarray.a
TEST	= test.out

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror


${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

test: ${TEST}
${TEST}: ${NAME} .test/main.c
	gcc -o ${TEST} \
	.test/main.c -L ./ -ldynarray
	${CFlAGS} \

${OBJS}: ${HDRS}

all: ${NAME} ${TEST}

clean:
	rm -f ${OBJS}
	rm -f *.gch

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re test
