/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:21:20 by mben-cha          #+#    #+#             */
/*   Updated: 2025/12/31 20:34:48 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void    draw_wall_column(t_game_state *game, t_ray *ray, t_draw *draw, int x)
{
    double          wallX;
    int             texture_x;
    int             texture_y;
    unsigned int    color;

    draw->step = 1.0 * draw->texture.height / draw->lineHeight;
    draw->texPos = (draw->drawStart - 1080.0 / 2 + draw->lineHeight / 2.0) * draw->step;
    while (draw->drawStart < draw->drawEnd)
    {
        texture_y = (int)draw->texPos;
        draw->texPos += draw->step;
        if (texture_y < 0) 
            texture_y = 0;
        if (texture_y >= draw->texture.height) 
            texture_y = draw->texture.height - 1;
        if (ray->side == 0)
            wallX = game->posY + ray->perpWallDist * ray->rayDirY;
        else
            wallX = game->posX + ray->perpWallDist * ray->rayDirX;
        wallX = wallX - floor(wallX);
        texture_x = (int)(wallX * draw->texture.width);
        color = my_mlx_pixel_get(&draw->texture.img_xpm, texture_x, texture_y);
        my_mlx_pixel_put(&game->img, x, draw->drawStart, color);
        draw->drawStart++;
    }
}

void    draw_wall(t_game_state *game, t_ray *ray, t_draw *draw, int x)
{
    if (ray->side == 0 && ray->rayDirX > 0)
    {
        //ray hit west wall
        draw->texture = game->textures[WE];
        draw_wall_column(game, ray, draw, x);
    }
    else if (ray->side == 0 && ray->rayDirX < 0)
    {
        //ray hit east wall
        draw->texture = game->textures[EA];
        draw_wall_column(game, ray, draw, x);
    }
    else if (ray->side == 1 && ray->rayDirY > 0)
    {
        //ray hit south wall
        draw->texture = game->textures[SO];
        draw_wall_column(game, ray, draw, x);
    }
    else if (ray->side == 1 && ray->rayDirY < 0)
    {
        //ray hit north wall
        draw->texture = game->textures[NO];
        draw_wall_column(game, ray, draw, x);
    }
}
