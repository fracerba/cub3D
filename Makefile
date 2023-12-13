# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fracerba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 12:32:24 by fracerba          #+#    #+#              #
#    Updated: 2023/01/04 12:32:30 by fracerba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D.a

OUT = cub3D

SRCS = cub3d.c \
		error.c \
		hooks.c \
		img.c \
		map.c \
		map2.c \
		map3.c \
		map4.c \
		map5.c \
		matrix.c \
		movement.c \
		movement2.c \
		raycast1.c \
		raycast2.c \
		raycast3.c \
		rgb.c \
		utils.c \
		utils2.c \
 
OBJS = ${SRCS:.c=.o}

CC = gcc -no-pie

RM = rm -f

FLAGS = -Wall -Werror -Wextra

LINKS = -Lminilibx-linux -L/usr/lib -Iminilibx-linux -lmlx -lXext -lX11 -lm -lz

LIBFT = libft

LIBFTNAME = libft.a
	
%.o: %.c
	${CC} ${FLAGS} -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

$(NAME): ${OBJS}
	make all -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	${CC} ${FLAGS} ${OBJS} ${NAME} ${LINKS} -o ${OUT}

all: ${NAME}

bonus:	${OBJS}
	make all -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	${CC} ${FLAGS} ${OBJS} ${NAME} ${LINKS} -o ${OUT}

clean: 
	${RM} ${OBJS}
	make clean -C ${LIBFT}

fclean: clean 
	${RM} ${NAME}
	${RM} ${OUT}
	make fclean -C ${LIBFT}

re: fclean all
