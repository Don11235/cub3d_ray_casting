#include "cub.h"

char **ft_malloc_map_grid(int height) {
  char **grid;
  int i;
  if (height <= 0)
    return NULL;
  grid = (char **)malloc(sizeof(char *) * (height + 1));
  if (!grid)
    return NULL;
  i = 0;
  while (i <= height) {
    grid[i] = NULL;
    i++;
  }
  return grid;
}
