SRCS= ./parsing/main.c ./parsing/parse_map.c ./parsing/parse_conf.c ./parsing/parse_utils.c\
	./parsing/parse_texture.c ./parsing/parse_color.c ./parsing/valide_map.c ./parsing/valide_map2.c\
	./parsing/parse_texture_2.c ./parsing/parse_color_2.c ./parsing/parse_conf_2.c 

NAME=cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./include -I$(LIBFT_DIR) #-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk #-g -fsanitize=address 

LIBFT_DIR = ./include/libft

LIBFT = $(LIBFT_DIR)/libft.a

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

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
