#include "./cub.h"

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
  ft_parse_file(fd, config);
  return (0);
}
