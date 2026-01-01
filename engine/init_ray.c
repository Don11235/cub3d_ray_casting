/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:40:17 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/01 17:59:49 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void init_ray_basic(t_game_state *game, t_ray *ray, int x)
{
    ray->cameraX = -1 + 2 * ((double)x / 1920);
    ray->rayDirX = game->dirX + game->planeX * ray->cameraX;
    ray->rayDirY = game->dirY + game->planeY * ray->cameraX;
    ray->mapX = game->posX;
    ray->mapY = game->posY;
    ray->deltaDistX = fabs(1 / ray->rayDirX);
    ray->deltaDistY = fabs(1 / ray->rayDirY);
    ray->hit = 0;
}

static void init_ray_step(t_game_state *game, t_ray *ray)
{
    if (ray->rayDirX < 0)
    {
        ray->stepX = -1;
        ray->sideDistX = (game->posX - ray->mapX) * ray->deltaDistX;
    }
    else
    {
        ray->stepX = 1;
        ray->sideDistX = (ray->mapX + 1.0 - game->posX) * ray->deltaDistX;
    }
    if (ray->rayDirY < 0)
    {
        ray->stepY = -1;
        ray->sideDistY = (game->posY - ray->mapY) * ray->deltaDistY;
    }
    else
    {
        ray->stepY = 1;
        ray->sideDistY = (ray->mapY + 1.0 - game->posY) * ray->deltaDistY;
    }
}


void    init_ray(t_game_state *game, t_ray *ray, int x)
{
    init_ray_basic(game, ray, x);
    init_ray_step(game, ray);
}