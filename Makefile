SRC_DIR = ./

MY_SOURCES = ft_printf.c ft_printf_utils.c
MY_OBJECTS = $(MY_SOURCES:.c=.o)

SRCS = $(addprefix $(SRC_DIR)/,$(MY_SOURCES))
OBJS = $(addprefix $(SRC_DIR)/,$(MY_OBJECTS))
LIBC = ar rc
LIBR = ranlib
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}
		${LIBR} ${NAME}

all:	${NAME}

clean:
	rm -f ${MY_OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

