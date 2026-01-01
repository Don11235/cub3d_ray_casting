/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:50:00 by mben-cha          #+#    #+#             */
/*   Updated: 2025/12/31 23:44:09 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void camera_move_forward_backward(t_game_state *game, double moveSpeed)
{
    if (game->keys['W'] == 1)
    {
        if (game->config->map.grid[(int)game->posY][(int)(game->posX + game->dirX * moveSpeed)] == '0')
            game->posX = game->posX + game->dirX * moveSpeed;
        if (game->config->map.grid[(int)(game->posY + game->dirY * moveSpeed)][(int)game->posX] == '0')
             game->posY = game->posY + game->dirY * moveSpeed; 
    }
    if (game->keys['S'] == 1)
    {
        if (game->config->map.grid[(int)game->posY][(int)(game->posX - game->dirX * moveSpeed)] == '0')
            game->posX = game->posX - game->dirX * moveSpeed;
        if (game->config->map.grid[(int)(game->posY - game->dirY * moveSpeed)][(int)game->posX] == '0')
             game->posY = game->posY - game->dirY * moveSpeed; 
    }
}

void camera_move_left_right(t_game_state *game, double moveSpeed)
{
    if (game->keys['A'] == 1)
    {
        if (game->config->map.grid[(int)game->posY][(int)(game->posX - game->dirY * moveSpeed)] == '0')
            game->posX = game->posX - game->dirY * moveSpeed;
        if (game->config->map.grid[(int)(game->posY - game->dirX * moveSpeed)][(int)game->posX] == '0')
            game->posY = game->posY + game->dirX * moveSpeed; 
    }
    if (game->keys['D'] == 1)
    {
        if (game->config->map.grid[(int)game->posY][(int)(game->posX - (-game->dirY * moveSpeed))] == '0')
            game->posX = game->posX + game->dirY * moveSpeed; // game->posX = game->posX - (-game->dirY * moveSpeed)
        if (game->config->map.grid[(int)(game->posY - game->dirX * moveSpeed)][(int)game->posX] == '0')
            game->posY = game->posY - game->dirX * moveSpeed;
    }
}

void    camera_move(t_game_state *game)
{
    double  moveSpeed;
    
    moveSpeed = game->frameTime * 5;
    camera_move_forward_backward(game, moveSpeed);
    camera_move_left_right(game, moveSpeed);
}
