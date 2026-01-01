/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:50:00 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/01 20:18:20 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void camera_move_forward_backward(t_game_state *game, double moveSpeed)
{
    int y;
    int x;
    
    if (game->keys['W'] == 1)
    {
        y = (int)game->posY;
        x = (int)(game->posX + game->dirX * moveSpeed);
        if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
            game->posX = game->posX + game->dirX * moveSpeed;
        y = (int)(game->posY + game->dirY * moveSpeed);
        x = (int)game->posX;
        if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
            game->posY = game->posY + game->dirY * moveSpeed; 
    }
    if (game->keys['S'] == 1)
    {
        y = (int)game->posY;
        x = (int)(game->posX - game->dirX * moveSpeed);
        if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
            game->posX = game->posX - game->dirX * moveSpeed;
        y = (int)(game->posY - game->dirY * moveSpeed);
        x = (int)game->posX;
        if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
             game->posY = game->posY - game->dirY * moveSpeed; 
    }
}

void camera_move_left_right(t_game_state *game, double moveSpeed)
{
    int y;
    int x;
    
    if (game->keys['A'] == 1)
    {
        y = (int)game->posY;
        x = (int)(game->posX - game->dirY * moveSpeed);
        if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
            game->posX = game->posX - game->dirY * moveSpeed;
        y = (int)(game->posY + game->dirX * moveSpeed);
        x = (int)game->posX;
        if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
            game->posY = game->posY + game->dirX * moveSpeed; 
    }
    if (game->keys['D'] == 1)
    {
        y = (int)game->posY;
        x = (int)(game->posX - (-game->dirY * moveSpeed));
        if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
            game->posX = game->posX + game->dirY * moveSpeed; // game->posX = game->posX - (-game->dirY * moveSpeed)
        y = (int)(game->posY - game->dirX * moveSpeed);
        x = (int)game->posX;
        if (is_inside_map(game, y, x) && game->config->map.grid[y][x] == '0')
            game->posY = game->posY - game->dirX * moveSpeed;
    }
}

void    camera_move(t_game_state *game)
{
    double  moveSpeed;
    
    moveSpeed = game->frameTime * 1.0;
    camera_move_forward_backward(game, moveSpeed);
    camera_move_left_right(game, moveSpeed);
}
