/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 23:10:08 by mohkhald          #+#    #+#             */
/*   Updated: 2026/01/03 23:23:22 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	ft_check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\n Enter: %s <filename>\n", argv[0]);
		return (1);
	}
	if (!ft_valid_file(argv[1]))
	{
		printf("Error\n Ivnalid <file>. valide: <filename.cub>\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_config	*config;

	if (ft_check_arg(argc, argv))
		return (EXIT_FAILURE);
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
	//run_engine(config);
	ft_free_config(config);
	return (0);
}
