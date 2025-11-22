#include "cub.h"

bool ft_is_color_line(char *line) {
  char *new_line;
  if (!line)
    return false;
  new_line = ft_skip_space(line);
  if (!new_line)
    return false;
  if (ft_strncmp(new_line, "F ", 2) == 0)
    return true;
  if (ft_strncmp(new_line, "C ", 2) == 0)
    return true;
  return false;
}

int *ft_handel_rgb(char *s) {
  char **split_rgb;
  int *rgb;
  if (!s)
    return NULL;
  split_rgb = ft_split(s, ',');
  if (!split_rgb || !split_rgb[0] || split_rgb[1] || split_rgb[2]) {
    ft_free_split(split_rgb);
    return NULL;
  }

  rgb = (int *)malloc(sizeof(int) * 3);
  if (!rgb)
    return NULL;
  int i = 0;
  while (i < 3) {
    rgb[i] = ft_atoi(split_rgb[i]);
    i++;
  }
  ft_free_split(split_rgb);
  return rgb;
}

bool ft_is_valid_rgb(int r, int g, int b) {
  if (r < 0 || r > 255)
    return false;
  if (g < 0 || g > 255)
    return false;
  if (b < 0 || b > 255)
    return false;
  return true;
}

void ft_fill_rgb_config(t_config *config, int *rgb, char *line) {
  if (ft_strncmp("F ", line, 2) == 0) {
    config->floor.r = rgb[0];
    config->floor.g = rgb[1];
    config->floor.b = rgb[2];
  }
  if (ft_strncmp("C ", line, 2) == 0) {
    config->ceil.r = rgb[0];
    config->ceil.g = rgb[1];
    config->ceil.b = rgb[2];
  }
}

void ft_fill_color_line(t_config *config, char *line) {
  char *new_line;
  char *color;
  int *rgb;
  new_line = ft_skip_space(line);
  color = ft_skip_space(new_line + 1);
  rgb = ft_handel_rgb(color);
  if (!rgb || !ft_is_valid_rgb(rgb[0], rgb[1], rgb[2])) {
    free(rgb);
    ft_exit_error();
  }
  ft_fill_rgb_config(config, rgb, new_line);
}
