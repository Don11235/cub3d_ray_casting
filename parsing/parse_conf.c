#include "../include/cub.h"

bool	ft_valid_file(char *file)
{
	size_t	len;
	char	*extention;

	len = ft_strlen(file);
	if (len < 5)
		return (false);
	extention = ft_strrchr(file, '.');
	if (!extention)
		return (false);
	if (ft_strcmp(".cub", extention) != 0)
		return (false);
	return (true);
}

int	ft_open_file(char *path)
{
	int	fd;

	if (!path)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

t_config	*ft_init_config(void)
{
	t_config	*config;

	config = ft_calloc(1, sizeof(t_config));
	if (!config)
		return (NULL);
	config->textures.north = NULL;
	config->textures.south = NULL;
	config->textures.west = NULL;
	config->textures.east = NULL;
	config->map.grid = NULL;
	config->map.width = 0;
	config->map.height = 0;
	config->player.x = -1;
	config->player.y = -1;
	config->floor_set = false;
	config->ceil_set = false;
	config->player.dire = '\0';
	return (config);
}

bool	ft_config_is_complete(t_config *config)
{
	if (!config)
		return (false);
	if (!config->textures.north || !config->textures.south)
		return (false);
	if (!config->textures.west || !config->textures.east)
		return (false);
	if (!config->floor_set || !config->ceil_set)
		return (false);
	if (!config->map.grid || config->map.height == 0)
		return (false);
	return (true);
}

int	ft_count_map_l(char *arr)
{
	int		fd;
	int		count;
	char	*line;
	char	*new_line;

	fd = ft_open_file(arr);
	if (fd < 0)
		return (-1);
	count = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		new_line = ft_strtrim(line, "\n");
		free(line);
		if (new_line)
		{
			if (ft_is_map_line(new_line))
				count++;
			free(new_line);
		}
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (count);
}
