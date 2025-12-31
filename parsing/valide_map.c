#include "../include/cub.h"

static int	ft_check_row(t_config *config, int row)
{
	int	col;
	int	count;

	col = 0;
	count = 0;
	while (config->map.grid[row][col])
	{
		if (ft_is_player_char(config->map.grid[row][col]))
		{
			config->player.x = col;
			config->player.y = row;
			config->player.dire = config->map.grid[row][col];
			count++;
		}
		col++;
	}
	return (count);
}

static bool	ft_player_pos(t_config *config)
{
	int	row;
	int	count;

	count = 0;
	row = 0;
	while (row < config->map.height)
	{
		count += ft_check_row(config, row);
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

static bool	ft_valid_vertical(t_map *map)
{
	int	row;
	int	len;

	row = 0;
	while (row < map->height)
	{
		len = ft_strlen(map->grid[row]);
		if (len > 0)
		{
			if (map->grid[row][0] != ' ' && map->grid[row][0] != '1')
				return (false);
			if (map->grid[row][len - 1] != '1' && map->grid[row][len
				- 1] != ' ')
				return (false);
		}
		row++;
	}
	return (true);
}

bool	ft_valid_map(t_config *config)
{
	if (!config || !config->map.grid)
		return (false);
	if (!ft_player_pos(config))
		return (false);
	if (!ft_valid_horizontal(&config->map))
		return (false);
	if (!ft_valid_vertical(&config->map))
		return (false);
	if (!ft_check_map_gaps(&config->map, &config->player))
		return (false);
	config->valid = true;
	//config->map.grid[config->player.y][config->player.x] = '0'; //changed
	return (true);
}
