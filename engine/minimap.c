/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 01:58:07 by mohkhald          #+#    #+#             */
/*   Updated: 2026/01/05 02:41:01 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

#define SIZE 5
#define MARGIN 10

void	ft_draw(t_game_state *game, int scren_x, int scren_y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (scren_x + j >= 0 && scren_x + j < 800 && scren_y + i >= 0
				&& scren_y + i < 600)
			{
				my_mlx_pixel_put(&game->img, scren_x + j, scren_y + i, color);
			}
			j++;
		}
		i++;
	}
}

void	ft_draw_grid(t_game_state *game)
{
	int	x;
	int	y;
	int	scren_x;
	int	scren_y;
	int	color;

	y = 0;
	while (y < game->config->map.height)
	{
		x = 0;
		while (x < game->config->map.width)
		{
			scren_x = MARGIN + x * SIZE;
			scren_y = MARGIN + y * SIZE;
			if (game->config->map.grid[y][x] == '1')
				color = 0x808080;
			else if (game->config->map.grid[y][x] == '0'
					|| ft_is_player_char(game->config->map.grid[y][x]))
				color = 0x202020;
			else
				color = 0x000000;
			ft_draw(game, scren_x, scren_y, color);
		}
	}
}

void	ft_draw_minimap(t_game_state *game)
{
	ft_draw_grid(game);
	/* ft_draw_player(game); */
	/* ft_draw_direction(game); */
}
