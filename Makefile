MAKEFLAGS += --silent

HEADER = ./includes/

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
			${SRC}ft_sort_until_three_utils_2.c \

CHECKER_C =	${SRC}checker.c \
			${SRC}checker_utils.c \
			${SRC}checker_instruct.c \
			${SRC}checker_checking.c \

LIBFT_PATH = ${SRC}ft_printf/

LIBFT = -L ${LIBFT_PATH} -lftprintf

FILES_O = ${FILES_C:.c=.o}

CHECKER_O = ${CHECKER_C:.c=.o}

FILES_H = ${HEADER}ft_push_swap.h

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

CHECKER_NAME = checker

all: ${NAME} \
	 ${CHECKER_NAME} \

${LIBFT}:
	make -C ${LIBFT_PATH} all bonus

${NAME}: ${LIBFT} ${FILES_O}
	cc ${FLAGS} ${FILES_O} ${LIBFT} -I ${FILES_H} -o ${NAME} -lm \
		&& echo "Make done successfully" || echo "Compilation ERROR"

${CHECKER_NAME}: ${LIBFT} ${CHECKER_O}
	cc ${FLAGS} ${CHECKER_O} ${LIBFT} -I ${FILES_H} -o ${CHECKER_NAME} -lm \
		&& echo "Checker compilation sucess" || echo "Error compilating Checker"

clean:
	rm -f ${CHECKER_O} \
	&& echo "Checker object files deteles successfully" || echo "No checker objects files to delete"
	rm -f ${FILES_O} \
	&& echo "Objects files deteled successfully" || echo "No objects files to delete"
	make -C ${LIBFT_PATH} clean

fclean: clean
	rm -r ${NAME} \
	&& echo "${NAME} deleted correctly" || echo "No file to delete"
	rm -r ${CHECKER_NAME} \
	&& echo "${CHECKER_NAME} deleted correctly" || echo "No checker to delete"
	make -C ${LIBFT_PATH} fclean \
	&& echo "Fclean done successfully" || echo "Cleaning ERROR"

re: fclean all
