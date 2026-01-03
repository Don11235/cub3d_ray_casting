/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:07:14 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/04 00:49:43 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
#include "../include/minilibx/mlx.h"

static void	init_window_and_image(t_game_state *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1920, 1080, "Cube3D");
	game->img.img = mlx_new_image(game->mlx, 1920, 1080);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
}

static void	load_textures(t_game_state *game)
{
	int		i;
	char	*tmp_arr[4];

	i = 0;
	tmp_arr[0] = game->config->textures.east;
	tmp_arr[1] = game->config->textures.north;
	tmp_arr[2] = game->config->textures.south;
	tmp_arr[3] = game->config->textures.west;
	while (i < 4)
	{
		game->textures[i].img_xpm.img = mlx_xpm_file_to_image(game->mlx,
				tmp_arr[i], &game->textures[i].width,
				&game->textures[i].height);
		is_valid_texture(game, i, game->textures[i].img_xpm.img);
		i++;
	}
}

static void	init_camera(t_game_state *game)
{
	if (game->config->player.dire == 'N')
	{
		game->dir_x = 0;
		game->dir_y = 1;
	}
	else if (game->config->player.dire == 'S')
	{
		game->dir_x = 0;
		game->dir_y = -1;
	}
	else if (game->config->player.dire == 'E')
	{
		game->dir_x = 1;
		game->dir_y = 0;
	}
	else if (game->config->player.dire == 'W')
	{
		game->dir_x = -1;
		game->dir_y = 0;
	}
	game->pos_x = game->config->player.x + 0.5;
	game->pos_y = game->config->player.y + 0.5;
	game->plane_x = game->dir_y * 0.66;
	game->plane_y = game->dir_x * -0.66;
}

static void	init_input_state(t_game_state *game)
{
	game->keycode = -1;
	memset(game->keys, 0, sizeof(game->keys));
	game->time = getTicks();
	game->floor_c = game->config->floor.r 
		| game->config->floor.g | game->config->floor.b;
	game->ceiling_c = game->config->ceil.r 
		| game->config->ceil.g | game->config->ceil.b;
}

void	init_game(t_game_state *game, t_config *config)
{
	game->config = config;
	init_window_and_image(game);
	load_textures(game);
	init_camera(game);
	init_input_state(game);
}
