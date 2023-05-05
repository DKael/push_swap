# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 20:30:42 by hyungdki          #+#    #+#              #
#    Updated: 2023/05/04 22:43:46 by hyungdki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		push_swap_error.c \
		push_swap_parsing.c \
		push_swap1.c \
		push_swap2.c \
		push_swap3.c \
		push_swap4.c \
		push_swap5.c \
		push_swap6.c \
		push_swap7.c \
		double_linked_list1.c \
		double_linked_list2.c \
		double_linked_list3.c \
		quick_sort.c \
		stack_instructions1.c \
		stack_instructions2.c \
		stack_instructions3.c \

OBJS = 	${SRCS:.c=.o}

SRCS_BONUS =	main_bonus.c \
				push_swap_error_bonus.c \
                push_swap_parsing_bonus.c \
                double_linked_list1_bonus.c \
                double_linked_list2_bonus.c \
                double_linked_list3_bonus.c \
                stack_instructions1_bonus.c \
                stack_instructions2_bonus.c \
                stack_instructions3_bonus.c \
                quick_sort_bonus.c \

OBJS_BONUS = 	${SRCS_BONUS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L. -lft

LIBFT_DIR = libft

LIBFT_NAME = libft.a

ifdef WITH_BONUS
	TOTAL_OBJS = ${OBJS_BONUS}
	NAME = checker
else
	TOTAL_OBJS = ${OBJS}
	NAME = push_swap
endif

${NAME} : ${TOTAL_OBJS}
		make -C ${LIBFT_DIR} all
		cp ${LIBFT_DIR}/${LIBFT_NAME} ${LIBFT_NAME}
		${CC} ${CFLAGS} ${LDFLAGS} ${TOTAL_OBJS} -o $@

%.o :%.c
	${CC} ${CFLAGS} -c -I. $< -o $@

all : ${NAME}

clean:
	make -C ${LIBFT_DIR} clean
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: 
	make clean
	rm -f ${LIBFT_DIR}/${LIBFT_NAME}
	rm -f ${LIBFT_NAME}
	rm -f push_swap
	rm -f checker

re: 
	make fclean
	make all

bonus:
	@make WITH_BONUS=1

.PHONY: all clean fclean re bonus
