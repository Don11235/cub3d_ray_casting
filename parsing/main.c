#include "../include/cub.h"

void ft_print_config(t_config *config)
{
  int i;

  printf("\n=== CONFIG DATA ===\n\n");
  
  printf("TEXTURES:\n");
  printf("  North:  %s\n", config->textures.north ? config->textures.north : "(null)");
  printf("  South:  %s\n", config->textures.south ? config->textures.south : "(null)");
  printf("  West:   %s\n", config->textures.west ? config->textures.west : "(null)");
  printf("  East:   %s\n", config->textures.east ? config->textures.east : "(null)");
  
  printf("\nCOLORS:\n");
  printf("  Floor:   RGB(%d, %d, %d) [%s]\n", 
         config->floor.r, config->floor.g, config->floor.b,
         config->floor_set ? "SET" : "NOT SET");
  printf("  Ceiling: RGB(%d, %d, %d) [%s]\n", 
         config->ceil.r, config->ceil.g, config->ceil.b,
         config->ceil_set ? "SET" : "NOT SET");
  
  printf("\nPLAYER:\n");
  printf("  Position: (%d, %d)\n", config->player.x, config->player.y);
  printf("  Direction: '%c'\n", config->player.dire);
  
  printf("\nMAP:\n");
  printf("  Width:  %d\n", config->map.width);
  printf("  Height: %d\n", config->map.height);
  printf("  Grid:\n");
  i = 0;
  while (i < config->map.height && config->map.grid[i])
  {
    printf("    [%2d] '%s'\n", i, config->map.grid[i]);
    i++;
  }
  
  printf("\nVALIDATION:\n");
  printf("  Valid: %s\n", config->valid ? "YES" : "NO");
  printf("\n===================\n\n");
}

int main(int argc, char **argv) {
  t_config *config;

  if (argc != 2) {
    printf("Error\n Enter: %s <filename>\n", argv[0]);
    return (EXIT_FAILURE);
  }
  if (!ft_valid_file(argv[1])) {
    printf("Error\n Ivnalid <file>. valide: <filename.cub>\n");
    return (EXIT_FAILURE);
  }
  config = ft_init_config();
  if (!config) {
    printf("Error\n malloc\n");
    return (EXIT_FAILURE);
  }
  ft_parse_file(argv[1], config);
  if (!ft_config_is_complete(config))
    ft_free_error("config not complete\n", config);
  if (!ft_valid_map(config))
    ft_free_error("map not valide\n", config);
  
  //ft_print_config(config);
  run_engine(config);
  ft_free_config(config);
  return (0);
}
