/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:50:26 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/01 18:17:14 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void    camera_rotate(t_game_state *game)
{
    double  rotSpeed;

    rotSpeed = game->frameTime * 0.5;
    if (game->keys[123] == 1)
    {
        double oldDirX = game->dirX;
        game->dirX = oldDirX * cos(rotSpeed) - game->dirY * sin(rotSpeed);
        game->dirY = oldDirX * sin(rotSpeed) + game->dirY * cos(rotSpeed);

        double oldPlaneX = game->planeX;
        game->planeX = oldPlaneX * cos(rotSpeed) - game->planeY * sin(rotSpeed);
        game->planeY = oldPlaneX * sin(rotSpeed) + game->planeY * cos(rotSpeed);
    }
    if (game->keys[124] == 1)
    {
        double oldDirX = game->dirX;
        game->dirX = oldDirX * cos(-rotSpeed) - game->dirY * sin(-rotSpeed);
        game->dirY = oldDirX * sin(-rotSpeed) + game->dirY * cos(-rotSpeed);

        double oldPlaneX = game->planeX;
        game->planeX = oldPlaneX * cos(-rotSpeed) - game->planeY * sin(-rotSpeed);
        game->planeY = oldPlaneX * sin(-rotSpeed) + game->planeY * cos(-rotSpeed);
    }
}
