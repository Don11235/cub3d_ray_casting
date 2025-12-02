#include "../include/cub.h"

int	main(int argc, char **argv)
{
	t_config	*config;

	if (argc != 2)
	{
		printf("Error\n Enter: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (!ft_valid_file(argv[1]))
	{
		printf("Error\n Ivnalid <file>. valide: <filename.cub>\n");
		return (EXIT_FAILURE);
	}
	config = ft_init_config();
	if (!config)
	{
		printf("Error\n malloc\n");
		return (EXIT_FAILURE);
	}
	ft_parse_file(argv[1], config);
	if (!ft_config_is_complete(config))
		ft_free_error("config not complete\n", config);
	if (!ft_valid_map(config))
		ft_free_error("map not valide\n", config);
	ft_free_config(config);
	return (0);
}
