#include "./cub.h"
#include <cstddef>
#include <cstdio>

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
    return (NULL);
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
  return (config);
}

void ft_parse_file(int fd, t_config *config) {
  char *line;
  char *new_line;
  int len;
  int row;

  row = 0;
  config->map.grid = ft_malloc_map_grid(100);
  line = ft_get_next_line(fd);
  while (line) {
    new_line = ft_strtrim(line, " \t\n");
    free(line);
    if (new_line && new_line[0] != '\0') {
      if (ft_is_texture_line(new_line))
        ft_fill_textu_path(config, new_line);
      else if (ft_is_color_line(new_line))
        ft_fill_color_path(config, new_line);
      else if (ft_is_map_line(new_line)) {
        len = ft_strlen(new_line);
        if (len > config->map.width)
          config->map.width = len;
        ft_fill_map(config->map.grid, new_line, row++);
        free(new_line);
        new_line = NULL;
      }
    }
    if (new_line)
      free(new_line);
    line = ft_get_next_line(fd);
  }
  config->map.height = row;
}
