#ifndef CUB_H
#define CUB_H

#include "./libft/libft.h"
#include "./mlx/mlx.h"
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_texture {
  char *north;
  char *south;
  char *west;
  char *east;
} t_texture;

typedef struct s_color {
  int r;
  int g;
  int b;
} t_color;

typedef struct s_player {
  int x;
  int y;
  char dire;
} t_player;

typedef struct s_map {
  char **grid;
  int width;
  int height;
} t_map;

typedef struct s_config {
  t_texture textures;
  t_color floor;
  t_color ceil;
  t_map map;
  t_player player;
} t_config;

/*Parse functions*/
bool ft_valid_file(char *file);
int ft_open_file(char *path);
void ft_parse_file(int fd, t_config *config);
t_config *ft_init_config(void);

/*map functions*/
char **ft_malloc_map_grid(int height);
#endif
