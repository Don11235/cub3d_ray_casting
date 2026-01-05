/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:00:53 by mben-cha          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/05 19:02:21 by mben-cha         ###   ########.fr       */
=======
/*   Updated: 2026/01/04 23:20:28 by mohkhald         ###   ########.fr       */
>>>>>>> fbb4992c5933079132cdbbced4d0c50c1112f02f
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
#include "../include/minilibx/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	key_press(int keycode, t_game_state *game)
{
	if (keycode == 13)
		game->keys['W'] = 1;
	if (keycode == 1)
		game->keys['S'] = 1;
	if (keycode == 0)
		game->keys['A'] = 1;
	if (keycode == 2)
		game->keys['D'] = 1;
	if (keycode == 123)
		game->keys[123] = 1;
	if (keycode == 124)
		game->keys[124] = 1;
	if (keycode == 53)
		ft_close_game(game);
	return (0);
}

int	key_release(int keycode, t_game_state *game)
{
	if (keycode == 13)
		game->keys['W'] = 0;
	if (keycode == 1)
		game->keys['S'] = 0;
	if (keycode == 0)
		game->keys['A'] = 0;
	if (keycode == 2)
		game->keys['D'] = 0;
	if (keycode == 123)
		game->keys[123] = 0;
	if (keycode == 124)
		game->keys[124] = 0;
	return (0);
}

int	ft_close_game(t_game_state *game)
{
	int	i;

<<<<<<< HEAD
=======
	// Destroy all texture images
>>>>>>> fbb4992c5933079132cdbbced4d0c50c1112f02f
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img_xpm.img)
			mlx_destroy_image(game->mlx, game->textures[i].img_xpm.img);
		i++;
	}
<<<<<<< HEAD
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
=======
	// Destroy main image
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	// Destroy window
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	// Free config data
>>>>>>> fbb4992c5933079132cdbbced4d0c50c1112f02f
	ft_free_config(game->config);
	exit(0);
	return (0);
}
/* int	close_game(t_game_state *game) */
/* { */
/* 	mlx_destroy_image(game->mlx, game->img.img); */
/* 	mlx_destroy_image(game->mlx, game->textures[0].img_xpm.img); */
/* 	mlx_destroy_image(game->mlx, game->textures[1].img_xpm.img); */
/* 	mlx_destroy_image(game->mlx, game->textures[2].img_xpm.img); */
/* 	mlx_destroy_image(game->mlx, game->textures[3].img_xpm.img); */
/* 	mlx_destroy_window(game->mlx, game->mlx_win); */
/* 	ft_free_config(game->config); */
/* 	exit(0); */
/* 	return (0); */
/* } */
