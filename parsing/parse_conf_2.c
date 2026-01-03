#include "../include/cub.h"

static void	ft_handel_line(char *line, t_config *config, int *row)
{
	int	len;

	if (ft_is_texture_line(line))
	{
		if (*row > 0)
			ft_free_error("map note valide\n", config);
		ft_fill_textu_path(config, line);
	}
	else if (ft_is_color_line(line))
	{
		if (*row > 0)
			ft_free_error("map note valide\n", config);
		ft_fill_color_conf(config, line);
	}
	else if (ft_is_map_line(line))
	{
		len = ft_strlen(line);
		if (len > config->map.width)
			config->map.width = len;
		ft_fill_map(config->map.grid, line, *row);
		(*row)++;
		config->map.height = *row;
	}
	else if (config->map.grid && line && line[0])
	{
		ft_free_error("invalid map line\n", config);
	}
}

static void	ft_read_line(int fd, t_config *config, int *row)
{
	char	*line;
	char	*new_line;

	line = ft_get_next_line(fd);
	while (line)
	{
		new_line = ft_strtrim(line, "\n");
		free(line);
		if (new_line && new_line[0] != '\0')
			ft_handel_line(new_line, config, row);
		free(new_line);
		line = ft_get_next_line(fd);
	}
}

void	ft_parse_file(char *arr, t_config *config)
{
	int	fd;
	int	map_l;
	int	row;

	map_l = ft_count_map_l(arr);
	if (map_l <= 0)
		ft_free_error("map not found\n", config);
	config->map.grid = ft_malloc_map_grid(map_l);
	if (!config->map.grid)
		ft_free_error("malloc map faild\n", config);
	fd = ft_open_file(arr);
	if (fd < 0)
		ft_free_error("cannot open file\n", config);
	row = 0;
	ft_read_line(fd, config, &row);
	close(fd);
}
