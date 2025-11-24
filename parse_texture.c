#include "cub.h"

static bool	ft_check_textu_dir(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}

bool	ft_is_texture_line(char *line)
{
	char	*new_line;

	if (!line)
		return (false);
	new_line = ft_skip_space(line);
	if (!new_line)
		return (false);
	if (ft_check_textu_dir(new_line))
		return (true);
	return (false);
}

char	*ft_extract_path(char *line)
{
	char	*path;
	char	*new_path;

	if (!line)
		return (NULL);
	path = ft_skip_space(line);
	if (!path || ft_strlen(path) < 3)
		return (NULL);
	path += 2;
	path = ft_skip_space(path);
	if (!path || !path[0])
		return (NULL);
	new_path = ft_strtrim(path, " \t\n");
	return (new_path);
}

bool	ft_is_valid_path(char *line)
{
	char	*exten;
	int		fd;

	if (!line)
		return (false);
	exten = ft_strchr(line, '.');
	if (!exten || ft_strcmp(exten, ".png") != 0)
		return (false);
	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

void	ft_fill_textu_path(t_config *config, char *line)
{
	char	*path;
	char	*new_path;

	path = ft_skip_space(line);
	new_path = ft_extract_path(path);
	/* printf("path: %s\n", new_path); */
	if (!new_path || !ft_is_valid_path(new_path))
		ft_free_error("Error\n", config);
	if (ft_strncmp(path, "NO ", 3) == 0)
		config->textures.north = new_path;
	else if (ft_strncmp(path, "WE ", 3) == 0)
		config->textures.west = new_path;
	else if (ft_strncmp(path, "EA ", 3) == 0)
		config->textures.east = new_path;
	else if (ft_strncmp(path, "SO ", 3) == 0)
		config->textures.south = new_path;
	else
		ft_free_error("Error\n", config);
}
