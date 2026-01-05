/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 23:10:54 by mohkhald          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/05 18:57:24 by mben-cha         ###   ########.fr       */
=======
/*   Updated: 2026/01/04 22:03:17 by mohkhald         ###   ########.fr       */
>>>>>>> fbb4992c5933079132cdbbced4d0c50c1112f02f
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_fill_rgb_config(t_config *config, int *rgb, char *line)
{
	if (ft_strncmp("F ", line, 2) == 0)
	{
		if (config->floor_set)
		{
			free(rgb);
			ft_free_error("duplicate floor color\n", config);
		}
		config->floor.r = rgb[0];
		config->floor.g = rgb[1];
		config->floor.b = rgb[2];
		config->floor_set = true;
	}
	else if (ft_strncmp("C ", line, 2) == 0)
	{
		if (config->ceil_set)
		{
			free(rgb);
			ft_free_error("duplicate ceil color\n", config);
		}
		config->ceil.r = rgb[0];
		config->ceil.g = rgb[1];
		config->ceil.b = rgb[2];
		config->ceil_set = true;
	}
}

void	ft_fill_color_conf(t_config *config, char *line)
{
	char	*new_line;
	char	*color;
	int		*rgb;

	new_line = ft_skip_space(line);
	color = ft_skip_space(new_line + 1);
	rgb = ft_handel_rgb(color);
	if (!rgb || !ft_is_valid_rgb(rgb[0], rgb[1], rgb[2]))
	{
		free(rgb);
		ft_free_error("color not valid!\n", config);
	}
	ft_fill_rgb_config(config, rgb, new_line);
	free(rgb);
}
