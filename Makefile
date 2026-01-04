SRCS= ./parsing/main.c ./parsing/parse_map.c ./parsing/parse_conf.c ./parsing/parse_utils.c\
	./parsing/parse_texture.c ./parsing/parse_color.c ./parsing/valide_map.c ./parsing/valide_map2.c\
	./parsing/parse_texture_2.c ./parsing/parse_color_2.c ./parsing/parse_conf_2.c\
	./engine/camera_move.c ./engine/camera_rotate.c ./engine/compute_wall.c ./engine/dda.c ./engine/draw_floor_ceiling.c\
	./engine/draw_wall.c ./engine/init_engine.c ./engine/init_ray.c ./engine/mlx_utils.c ./engine/render_walls.c\
	./engine/render.c ./engine/run_engine.c ./engine/update_frame_time.c ./engine/utils.c

NAME=cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./include -I$(LIBFT_DIR)

LDFLAGS = -L./include/minilibx -lmlx -framework OpenGL -framework AppKit 

LIBFT_DIR = ./include/libft

LIBFT = $(LIBFT_DIR)/libft.a

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

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
