#include "cub.h"

int	main(int argc, char **argv)
{
	t_config	*config;
	int			fd;

	if (argc != 2)
	{
		perror("Error\n");
		return (EXIT_FAILURE);
	}
	if (!ft_valid_file(argv[1]))
		perror("Error\n");
	fd = ft_open_file(argv[1]);
	if (fd < 0)
	{
		perror("Error\n");
		return (EXIT_FAILURE);
	}
	config = ft_init_config();
	if (!config)
	{
		close(fd);
		perror("Error\n");
		return (EXIT_FAILURE);
	}
	ft_parse_file(fd, config);
	close(fd);
	if (!ft_config_is_complete(config))
		ft_free_error("Error\n", config);
	if (!ft_valid_map(config))
		ft_free_error("Error\n", config);
	ft_free_config(config);
	return (0);
}
