#include "cub.h"

char	**ft_copy_grid(t_map *map)
{
	int		i;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		arr[i] = ft_strdup(map->grid[i]);
		if (!arr[i])
		{
			while (--i >= 0)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int	ft_recursive_check(char **arr, int x, int y, int height)
{
	int	len_r;

	if (y < 0 || y >= height)
		return (0);
	len_r = ft_strlen(arr[y]);
	if (x < 0 || x >= len_r || arr[y][x] == ' ')
		return (0);
	if (arr[y][x] == '1' || arr[y][x] == 'o')
		return (1);
	arr[y][x] = 'o';
	if (!ft_recursive_check(arr, x + 1, y, height))
		return (0);
	if (!ft_recursive_check(arr, x - 1, y, height))
		return (0);
	if (!ft_recursive_check(arr, x, y + 1, height))
		return (0);
	if (!ft_recursive_check(arr, x, y - 1, height))
		return (0);
	return (1);
}

bool	ft_check_map_gaps(t_map *map, t_player *player)
{
	char	**arr;
	int		result;
	int		i;

	arr = ft_copy_grid(map);
	if (!arr)
		return (false);
	result = ft_recursive_check(arr, player->x, player->y, map->height);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (result);
}
