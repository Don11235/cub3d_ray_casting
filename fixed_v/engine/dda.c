/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:47:14 by mben-cha          #+#    #+#             */
/*   Updated: 2025/12/31 15:30:04 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void    dda(t_game_state *game, t_ray *ray)
{
    while (ray->hit == 0)
    {
        if (ray->sideDistX < ray->sideDistY)
        {
            ray->sideDistX = ray->sideDistX + ray->deltaDistX;
            ray->mapX = ray->mapX + ray->stepX;
            ray->side = 0;
        }
        else 
        {
            ray->sideDistY = ray->sideDistY + ray->deltaDistY;
            ray->mapY = ray->mapY + ray->stepY;
            ray->side = 1;
        }
        if (game->config->map.grid[ray->mapY][ray->mapX] == '1')
            ray->hit = 1;
    }
}
