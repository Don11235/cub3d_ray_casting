#include "cub.h"

static bool	ft_is_valid_map(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	if (c == 'S' || c == 'N' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	ft_is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line || !line[0])
		return (false);
	while (line[i])
	{
		if (!ft_is_valid_map(line[i]))
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

void	ft_fill_map(char **grid, char *line, int row)
{
	if (!grid || !line || row < 0)
		return ;
	grid[row] = ft_strdup(line);
	if (!grid[row])
		return ;
}
