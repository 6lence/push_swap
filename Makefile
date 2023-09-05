MAKEFLAGS += --silent

SRC = ./src/

FILES_C =	${SRC}main.c \
			${SRC}ft_error_utils.c \
			${SRC}ft_verifs_utils.c \
			${SRC}ft_lst_utils.c \
			${SRC}ft_lst_utils_2.c \
			${SRC}ft_algo.c \
			${SRC}ft_algo_utils.c \
			${SRC}ft_algo_utils_2.c \
			${SRC}ft_algo_utils_3.c \
			${SRC}ft_sort_until_three.c \
			${SRC}ft_sort_until_three_utils.c \

LIBFT_PATH = ${SRC}ft_printf/

LIBFT = -L ${LIBFT_PATH} -lftprintf

FILES_O = ${FILES_C:.c=.o}

FILES_H = ./ft_push_swap.h

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

all: ${NAME}

${LIBFT}:
	make -C ${LIBFT_PATH} all bonus

${NAME}: ${LIBFT} ${FILES_O}
	cc ${FLAGS} ${FILES_O} ${LIBFT} -I ${FILES_H} -o ${NAME} -lm \
		&& echo "Make done successfully" || echo "Compilation ERROR"

clean:
	rm -f ${FILES_O} \
	&& echo "Objects files deteled successfully" || echo "No objects files to delete"
	make -C ${LIBFT_PATH} clean

fclean: clean
	rm -r ${NAME} \
	&& echo "${NAME} deleted correctly" || echo "No file to delete"
	make -C ${LIBFT_PATH} fclean \
	&& echo "Fclean done successfully" || echo "Cleaning ERROR"

re: fclean all
