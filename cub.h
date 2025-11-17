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

typedef struct s_textuers {
  char *path;
} t_textuers;

typedef struct s_map {
  char **grid;
  int width;
  int height;
} t_map;

typedef struct s_config {
  t_textuers text[4];
  int f_color;
  int cel_color;
  int player_x;
  int player_y;
  int player_dir;
} t_config;

#endif
