/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:07:14 by mben-cha          #+#    #+#             */
/*   Updated: 2025/12/31 20:39:18 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
#include "../include/minilibx/mlx.h"

static void load_textures(t_game_state *game) {
  int i;
  char *tmp_arr[4];

  i = 0;
  tmp_arr[0] = game->config->textures.east;
  tmp_arr[1] = game->config->textures.north;
  tmp_arr[2] = game->config->textures.south;
  tmp_arr[3] = game->config->textures.west;
  while (i < 4) {
    game->textures[i].img_xpm.img =
        mlx_xpm_file_to_image(game->mlx, tmp_arr[i], &game->textures[i].width,
                              &game->textures[i].height);
    if (!game->textures[i].img_xpm.img)
      ft_free_error("invalid texture\n", game->config);
    game->textures[i].img_xpm.addr =
        mlx_get_data_addr(game->textures[i].img_xpm.img,
                          &game->textures[i].img_xpm.bits_per_pixel,
                          &game->textures[i].img_xpm.line_length,
                          &game->textures[i].img_xpm.endian);
    i++;
  }
}

static void init_camera(t_game_state *game) {
  if (game->config->player.dire == 'N') {
    game->dirX = 0;
    game->dirY = 1;
  } else if (game->config->player.dire == 'S') {
    game->dirX = 0;
    game->dirY = -1;
  } else if (game->config->player.dire == 'E') {
    game->dirX = 1;
    game->dirY = 0;
  } else if (game->config->player.dire == 'W') {
    game->dirX = -1;
    game->dirY = 0;
  }
  game->posX = game->config->player.x;
  game->posY = game->config->player.y;
  game->planeX = game->dirY * 0.66;
  game->planeY = game->dirX * -0.66;
}

static void init_input_state(t_game_state *game) {
  /*game->floor_c = game->config->floor.r | game->config->floor.g |
game->config->floor.b; game->ceiling_c = game->config->ceil.r |
game->config->ceil.g | game->config->ceil.b;*/
  game->keycode = -1;
  ft_memset(game->keys, 0, sizeof(game->keys));
  game->time = getTicks();
  game->floor_c = (game->config->floor.r << 16) | (game->config->floor.g << 8) |
                  game->config->floor.b;
  game->ceiling_c = (game->config->ceil.r << 16) | (game->config->ceil.g << 8) |
                    game->config->ceil.b;
}

void init_game(t_game_state *game, t_config *config) {
  game->config = config;
  game->mlx = mlx_init();
  game->mlx_win = mlx_new_window(game->mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
  game->img.img = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
  game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
                                     &game->img.line_length, &game->img.endian);
  load_textures(game);
  init_camera(game);
  init_input_state(game);
  mlx_loop_hook(game->mlx, redraw, game);
  mlx_hook(game->mlx_win, 2, 1L << 0, keyPress, game);
  mlx_hook(game->mlx_win, 3, 1L << 1, keyRelease, game);
  mlx_hook(game->mlx_win, 17, 0, Close, game);
}