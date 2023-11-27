CC=gcc
FLAGS= -no-pie -Wall -Wextra -Werror
NAME=cub3D.a
OUT=cub3D

FILES= cub3d.c hooks.c matrix.c rgb.c utils.c
OBJECTS=$(FILES:.c=.o)

LIBFT=libft/
LIBFTNAME=libft.a

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBFT)
	mv $(LIBFT)$(LIBFTNAME) $(NAME)
	$(CC) $(FLAGS) $(OBJECTS) $(NAME) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(OUT)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)
	$(MAKE) clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)$(LIBFTNAME)

re:	fclean $(NAME)

bonus: $(OBJECTS)
	$(MAKE) bonus -C $(PRINTF)
	mv $(LIBFT)$(LIBFTNAME) $(NAME)
	$(CC) $(FLAGS) $(OBJECTS) $(NAME) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(OUT)

.PHONY:	all clean fclean re bonus
