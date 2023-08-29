MAKEFLAGS += --silent

SRC = ./src/

OBJ = ./obj/

FILES_C =	${SRC}main.c \
			${SRC}ft_utils.c \
			

LIBFT_PATH = ${SRC}ft_printf/

LIBFT = -L ${LIBFT_PATH} -lftprintf

FILES_O = ${FILES_C:.c=${OBJ}.o}

FILES_H = ./ft_push_swap.h

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

${LIBFT}
	make -C ${LIBFT_PATH} all bonus

${NAME}: ${LIBFT} ${FILES_O}
	CC ${FLAGS} ${FILES_O} ${LIBFT} -I ${FILES_H} -o ${NAME} -lm \
		&& echo "Make done successfully" || echo "ERROR"

clean:
	rm -f ${FILES_O}
	make -C ${LIBFT_PATH} clean

fclean:
	rm -r ${NAME}
	make -C ${LIBFT_PATH} fclean \
	&& echo "Fclean done successfully" || echo "ERROR"

re: fclean all
