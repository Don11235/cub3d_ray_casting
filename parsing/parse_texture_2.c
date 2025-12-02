#include "../include/cub.h"

static void	ft_fill_ea_so(t_config *config, char *path, char *new_path)
{
	if (ft_strncmp(path, "EA ", 3) == 0)
	{
		if (config->textures.east != NULL)
		{
			free(new_path);
			ft_free_error("Duplicate EA\n", config);
		}
		config->textures.east = new_path;
	}
	else if (ft_strncmp(path, "SO ", 3) == 0)
	{
		if (config->textures.south != NULL)
		{
			free(new_path);
			ft_free_error("Duplicate SO\n", config);
		}
		config->textures.south = new_path;
	}
}

static void	ft_fill_no_we(t_config *config, char *path, char *new_path)
{
	if (ft_strncmp(path, "NO ", 3) == 0)
	{
		if (config->textures.north != NULL)
		{
			free(new_path);
			ft_free_error("Duplicate NO\n", config);
		}
		config->textures.north = new_path;
	}
	else if (ft_strncmp(path, "WE ", 3) == 0)
	{
		if (config->textures.north != NULL)
		{
			free(new_path);
			ft_free_error("Duplicate WE\n", config);
		}
		config->textures.west = new_path;
	}
}

static void	ft_fill_texture(t_config *config, char *path, char *new_path)
{
	if (ft_strncmp(path, "NO ", 3) == 0 || ft_strncmp(path, "WE ", 3) == 0)
		ft_fill_no_we(config, path, new_path);
	else if (ft_strncmp(path, "EA ", 3) == 0 || ft_strncmp(path, "SO ", 3) == 0)
		ft_fill_ea_so(config, path, new_path);
	else
	{
		free(new_path);
		ft_free_error("path not found.\n", config);
	}
}

void	ft_fill_textu_path(t_config *config, char *line)
{
	char	*path;
	char	*new_path;

	path = ft_skip_space(line);
	new_path = ft_extract_path(path);
	if (!new_path || !ft_is_valid_path(new_path))
	{
		free(new_path);
		ft_free_error("invalid texture path.\n", config);
	}
	ft_fill_texture(config, path, new_path);
}
