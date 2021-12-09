# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 15:17:33 by rmonney           #+#    #+#              #
#    Updated: 2021/12/09 16:31:11 by rmonney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= get_next_line.c get_next_line_utils.c lemain.c ft_split.c verifmap.c game.c deal_key.c ft_itoa.c poubelle.c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

NAME		= so_long

FLAGS		= -Wall -Wextra -Werror

CC			= gcc

FRAMEWORK	= -framework OpenGL -framework AppKit

MLXPATH		= ./minilibx/

INCLUDEMLX	= -I ${MLXPATH}

LMLX		= -L ${MLXPATH} -lmlx

.c.o:		
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${MLXPATH}
			${CC} ${FLAGS} ${INCLUDEMLX} -o ${NAME} ${OBJS} ${LMLX} ${FRAMEWORK}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
