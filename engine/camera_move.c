/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:50:00 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/05 01:50:14 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	camera_move_forward_backward(t_game_state *game, double moveSpeed)
{
	int	y;
	int	x;

	if (game->keys['W'] == 1)
	{
		y = (int)game->pos_y;
		x = (int)(game->pos_x + game->dir_x * moveSpeed);
		if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
			game->pos_x = game->pos_x + game->dir_x * moveSpeed;
		y = (int)(game->pos_y + game->dir_y * moveSpeed);
		x = (int)game->pos_x;
		if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
			game->pos_y = game->pos_y + game->dir_y * moveSpeed;
	}
	if (game->keys['S'] == 1)
	{
		y = (int)game->pos_y;
		x = (int)(game->pos_x - game->dir_x * moveSpeed);
		if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
			game->pos_x = game->pos_x - game->dir_x * moveSpeed;
		y = (int)(game->pos_y - game->dir_y * moveSpeed);
		x = (int)game->pos_x;
		if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
			game->pos_y = game->pos_y - game->dir_y * moveSpeed;
	}
}

void	camera_move_left_right(t_game_state *game, double moveSpeed)
{
	int	y;
	int	x;

	if (game->keys['A'] == 1)
	{
		y = (int)game->pos_y;
		x = (int)(game->pos_x - game->dir_y * moveSpeed);
		if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
			game->pos_x = game->pos_x - game->dir_y * moveSpeed;
		y = (int)(game->pos_y + game->dir_x * moveSpeed);
		x = (int)game->pos_x;
		if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
			game->pos_y = game->pos_y + game->dir_x * moveSpeed;
	}
	if (game->keys['D'] == 1)
	{
		y = (int)game->pos_y;
		x = (int)(game->pos_x - (-game->dir_y * moveSpeed));
		if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
			game->pos_x = game->pos_x + game->dir_y * moveSpeed;
		y = (int)(game->pos_y - game->dir_x * moveSpeed);
		x = (int)game->pos_x;
		if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
			game->pos_y = game->pos_y - game->dir_x * moveSpeed;
	}
}

void	camera_move(t_game_state *game)
{
	double	move_speed;

	move_speed = game->frame_time * 4.0;
	camera_move_forward_backward(game, move_speed);
	camera_move_left_right(game, move_speed);
}
