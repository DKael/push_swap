# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmkael <hyungdki@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 20:46:38 by dmkael            #+#    #+#              #
#    Updated: 2023/04/20 20:46:40 by dmkael           ###   ########.fr        #
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

NAME = push_swap

# ifdef WITH_BONUS
# 	TOTAL_OBJS = ${OBJS_BONUS}
# else
# 	TOTAL_OBJS = ${OBJS}
# endif

${NAME} : ${OBJS}
		ar -rsc $@ $^
	
%.o :%.c
	${CC} ${CFLAGS} -c -I. $< -o $@

all : ${NAME}

clean:
	make -C ${LIBFT_DIR} clean
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: 
	make clean
	rm -f ${NAME} ${LIBFT_NAME}

re: 
	make fclean
	make all

bonus:
	@make WITH_BONUS=1

.PHONY: all clean fclean re bonus
