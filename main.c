#include "./cub.h"
#include "libft/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool ft_valid_file(char *file) {
  size_t len;
  char *extention;

  len = ft_strlen(file);
  if (len < 5)
    return (false);
  extention = ft_strchr(file, '.');
  if (ft_strcmp(".cub", extention) != 0)
    return (false);
  return (true);
}

int ft_open_file(char *str) {
  int fd;

  fd = open(str, O_RDONLY);
  if (fd < 0) {
    perror("file not found\n");
    return (-1);
  }
  return (fd);
}

int main(int argc, char **argv) {
  t_config *config;
  int fd;

  if (argc != 2) {
    perror("Error: argument not valid\n");
    return (EXIT_FAILURE);
  }
  if (!ft_valid_file(argv[1]))
    perror("file");
  fd = ft_open_file(argv[1]);
  if (fd < 0)
    return (EXIT_FAILURE);
  config = ft_init_config();
  if (!config) {
    close(fd);
    perror("malloc");
    return (EXIT_FAILURE);
  }
  ft_parse_file(int fd, t_config *config);
  return (0);
}
