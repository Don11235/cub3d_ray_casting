#include "cub.h"

char *ft_skip_space(char *line) {
  int i;

  i = 0;
  if (!line)
    return (NULL);
  while (line[i]) {
    if (line[i] != '\t' && line[i] != ' ')
      break;
    i++;
  }
  return (&line[i]);
}

void ft_free_split(char **s) {
  int i;

  i = 0;
  if (!s)
    return;
  while (s[i]) {
    free(s[i]);
    i++;
  }
  free(s);
}

void ft_free_config(t_config *config) {
  int i;

  if (!config)
    return;
  if (config->textures.east)
    free(config->textures.east);
  if (config->textures.west)
    free(config->textures.west);
  if (config->textures.north)
    free(config->textures.north);
  if (config->textures.south)
    free(config->textures.south);
  if (config->map.grid) {
    i = 0;
    while (i < config->map.height) {
      if (config->map.grid[i])
        free(config->map.grid[i]);
      i++;
    }
    free(config->map.grid);
  }
  free(config);
}

void ft_free_error(char *msg, t_config *config) {
  ft_putstr_fd("Error\n", 2);
  if (msg)
    ft_putstr_fd(msg, 2);
  ft_free_config(config);
  exit(EXIT_FAILURE);
}
