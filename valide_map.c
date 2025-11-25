#include "cub.h"
#include "libft/libft.h"

static bool	ft_valid_char(t_map *map)
{
	int	col;
	int	row;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (map->grid[row][col])
		{
			if (map->grid[row][col] != '1' && map->grid[row][col] != '0'
				&& map->grid[row][col] != ' ' && map->grid[row][col] != 'N'
				&& map->grid[row][col] != 'W' && map->grid[row][col] != 'S'
				&& map->grid[row][col] != 'E')
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}

static bool	ft_player_pos(t_config *config)
{
	int	row;
	int	col;
	int	count;

	count = 0;
	row = 0;
	while (row < config->map.height)
	{
		col = 0;
		while (config->map.grid[row][col])
		{
			if (config->map.grid[row][col] == 'N'
				|| config->map.grid[row][col] == 'W'
				|| config->map.grid[row][col] == 'S'
				|| config->map.grid[row][col] == 'E')
			{
				config->player.x = col;
				config->player.y = row;
				config->player.dire = config->map.grid[row][col];
				count++;
			}
			col++;
		}
		row++;
	}
	return (count == 1);
}

static bool	ft_valid_horizontal(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	while (map->grid[0][i])
	{
		if (map->grid[0][i] != '1' && map->grid[0][i] != ' ')
			return (false);
		i++;
	}
	i = 0;
	len = ft_strlen(map->grid[map->height - 1]);
	while (i < len)
	{
		if ((map->grid[map->height - 1][i] != '1') && (map->grid[map->height
				- 1][i] != ' '))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_valid_vertical(t_map *map)
{
	int	row;
	int	len;

	row = 0;
	while (row < map->height)
	{
		len = ft_strlen(map->grid[row]);
		if (len > 0)
		{
			if (map->grid[row][0] != '0' && map->grid[row][0] != '1')
				return (false);
			if (map->grid[row][len - 1] != '1' && map->grid[row][len
				- 1] != ' ')
				return (false);
		}
		row++;
	}
	return (true);
}

bool	ft_valid_map_edge(t_map *map)
{
	if (!ft_valid_horizontal(map))
		return (false);
	if (!ft_valid_vertical(map))
		return (false);
	return (true);
}

bool	ft_valid_map(t_config *config)
{
	if (!config || !config->map.grid)
		return (false);
	if (!ft_valid_char(&config->map))
		return (false);
	if (!ft_player_pos(config))
		return (false);
	if (!ft_valid_map_edge(&config->map))
		return (false);
	return (true);
}
