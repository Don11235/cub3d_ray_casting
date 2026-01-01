#include "../include/cub.h"

bool	ft_is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static bool	ft_is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	return (ft_is_player_char(c));
}

bool	ft_is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line || !line[0])
		return (false);
	while (line[i])
	{
		if (!ft_is_valid_map_char(line[i]))
			return (false);
		i++;
	}
	return (true);
}

char	**ft_malloc_map_grid(int height)
{
	char	**grid;
	int		i;

	if (height <= 0)
		return (NULL);
	grid = (char **)malloc(sizeof(char *) * (height + 1));
	if (!grid)
		return (NULL);
	i = 0;
	while (i <= height)
	{
		grid[i] = NULL;
		i++;
	}
	return (grid);
}

bool	ft_fill_map(char **grid, char *line, int row)
{
	if (!grid || !line || row < 0)
		return (false);
	grid[row] = ft_strdup(line);
	if (!grid[row])
		return (false);
	return (true);
}
