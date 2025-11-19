#include "./cub.h"

bool ft_valid_file(char *file) {
  size_t len;
  char *extention;

  len = ft_strlen(file);
  if (len < 5) {
    perror("file");
    return (false);
  }
  extention = ft_strchr(file, '.');
  if (!extention)
    return (false);
  if (ft_strcmp(".cub", extention) != 0)
    return (false);
  return (true);
}

int ft_open_file(char *path) {
  int fd;

  if (!path)
    return (-1);
  fd = open(path, O_RDONLY);
  if (fd < 0) {
    perror("file\n");
  }
  return (fd);
}

t_config *ft_init_config(void) {
  t_config *config;

  config = (t_config *)ft_calloc(1, sizeof(t_config));
  if (!config)
    return NULL;
  config->textures.north = NULL;
  config->textures.south = NULL;
  config->textures.west = NULL;
  config->textures.east = NULL;
  config->map.grid = NULL;
  config->map.width = 0;
  config->map.height = 0;
  config->player.x = -1;
  config->player.y = -1;
  config->player.dire = '\0';
  return config;
}
