/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:15:43 by mben-cha          #+#    #+#             */
/*   Updated: 2025/12/30 22:32:31 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void    compute_wall(t_ray *ray, t_draw *draw)
{
    if (ray->side == 0)
        ray->perpWallDist = ray->sideDistX - ray->deltaDistX;
    else
        ray->perpWallDist = ray->sideDistY - ray->deltaDistY;
    draw->lineHeight = (int)(1080 / ray->perpWallDist);
    draw->drawStart = 1080 / 2 - draw->lineHeight / 2;
    if (draw->drawStart < 0)
        draw->drawStart = 0;
    draw->drawEnd = 1080 / 2 + draw->lineHeight / 2;
    if(draw->drawEnd >= 1080)
        draw->drawEnd = 1080 - 1;
}
