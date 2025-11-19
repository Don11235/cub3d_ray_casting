SRCS= main.c parse_map.c parse_conf.c

NAME=cub

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./include -I$(LIBFT_DIR)
LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o: %.c cub.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
