#include "cub.h"

static bool	ft_valid_char(t_config *config)
{
	int	col;
	int	row;

	row = 0;
	while (config->map.grid[row])
	{
		col = 0;
		while (config->map.grid[row][col])
		{
			if (config->map.grid[row][col] != '1'
				|| config->map.grid[row][col] != '0'
				|| config->map.grid[row][col] != ' '
				|| config->map.grid[row][col] != 'N'
				|| config->map.grid[row][col] != 'W'
				|| config->map.grid[row][col] != 'S'
				|| config->map.grid[row][col] != 'E')
				return (false);
			col++;
		}
			row++;
	}
	return (true);
}

bool	ft_valid_map(t_config *config)
{
	if (!config || !config->map.grid)
		return (false);
	if (!ft_valid_char(config))
		return (false);
	return (true);
}
