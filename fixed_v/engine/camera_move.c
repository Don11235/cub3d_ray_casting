/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:50:00 by mben-cha          #+#    #+#             */
/*   Updated: 2025/12/31 16:03:37 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

//add a function to check if the new position is within map bounds 
static int	is_valid_map_coord(t_game_state *game, int x, int y)
{
	if (x < 0 || x >= game->config->map.width || y < 0 || y >= game->config->map.height)
		return (0);
	return (1);
}

void	camera_move_forward_backward(t_game_state *game, double moveSpeed)
{
	double	new_pos_x;
	double	new_pos_y;
	int		map_grid_x;
	int		map_grid_y;

	if (game->keys['W'] == 1)
	{
		new_pos_x = game->posX + game->dirX * moveSpeed;
		new_pos_y = game->posY + game->dirY * moveSpeed;
		map_grid_x = (int)new_pos_x;
		map_grid_y = (int)new_pos_y;

		if (is_valid_map_coord(game, map_grid_x, (int)game->posY) && game->config->map.grid[(int)game->posY][map_grid_x] == '0')
			game->posX = new_pos_x;
		if (is_valid_map_coord(game, (int)game->posX, map_grid_y) && game->config->map.grid[map_grid_y][(int)game->posX] == '0')
			game->posY = new_pos_y;
	}
	if (game->keys['S'] == 1)
	{
		new_pos_x = game->posX - game->dirX * moveSpeed;
		new_pos_y = game->posY - game->dirY * moveSpeed;
		map_grid_x = (int)new_pos_x;
		map_grid_y = (int)new_pos_y;

		if (is_valid_map_coord(game, map_grid_x, (int)game->posY) && game->config->map.grid[(int)game->posY][map_grid_x] == '0')
			game->posX = new_pos_x;
		if (is_valid_map_coord(game, (int)game->posX, map_grid_y) && game->config->map.grid[map_grid_y][(int)game->posX] == '0')
			game->posY = new_pos_y;
	}
}

void	camera_move_left_right(t_game_state *game, double moveSpeed)
{
	double	new_pos_x;
	double	new_pos_y;
	int		map_grid_x;
	int		map_grid_y;

	if (game->keys['A'] == 1)
	{
		new_pos_x = game->posX - game->dirY * moveSpeed;
		new_pos_y = game->posY + game->dirX * moveSpeed;
		map_grid_x = (int)new_pos_x;
		map_grid_y = (int)new_pos_y;

		if (is_valid_map_coord(game, map_grid_x, (int)game->posY) && game->config->map.grid[(int)game->posY][map_grid_x] == '0')
			game->posX = new_pos_x;
		if (is_valid_map_coord(game, (int)game->posX, map_grid_y) && game->config->map.grid[map_grid_y][(int)game->posX] == '0')
			game->posY = new_pos_y;
	}
	if (game->keys['D'] == 1)
	{
		new_pos_x = game->posX + game->dirY * moveSpeed;
		new_pos_y = game->posY - game->dirX * moveSpeed;
		map_grid_x = (int)new_pos_x;
		map_grid_y = (int)new_pos_y;

		if (is_valid_map_coord(game, map_grid_x, (int)game->posY) && game->config->map.grid[(int)game->posY][map_grid_x] == '0')
			game->posX = new_pos_x;
		if (is_valid_map_coord(game, (int)game->posX, map_grid_y) && game->config->map.grid[map_grid_y][(int)game->posX] == '0')
			game->posY = new_pos_y;
	}
}

void    camera_move(t_game_state *game)
{
    double  moveSpeed;
    
    moveSpeed = game->frameTime * 5;
    camera_move_forward_backward(game, moveSpeed);
    camera_move_left_right(game, moveSpeed);
}
