# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 20:30:42 by hyungdki          #+#    #+#              #
#    Updated: 2023/05/03 20:30:42 by hyungdki         ###   ########.fr        #
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

# SRCS_BONUS =	ft_printf_bonus.c \
# 				ft_printf_utils_bonus.c \
# 				case_c_bonus.c \
# 				case_d_and_i_bonus.c \
# 				case_p_bonus.c \
# 				case_percent_bonus.c \
# 				case_s_bonus.c \
# 				case_u_bonus.c \
# 				case_x_bonus.c \
# 				ft_itoa_hex_bonus.c \
# 				ft_itoa_ptr_bonus.c \
# 				ft_itoa_unsigned_bonus.c

# OBJS_BONUS = 	${SRCS_BONUS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L. -lft

NAME = push_swap

LIBFT_DIR = libft

LIBFT_NAME = libft.a

ifdef WITH_BONUS
	TOTAL_OBJS = ${OBJS_BONUS}
else
	TOTAL_OBJS = ${OBJS}
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
	rm -f ${NAME}

re: 
	make fclean
	make all

bonus:
	@make WITH_BONUS=1

.PHONY: all clean fclean re bonus
