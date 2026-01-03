/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:47:14 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/03 20:01:30 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	dda(t_game_state *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x = ray->side_dist_x + ray->delta_dist_x;
			ray->map_x = ray->map_x + ray->step_x;
			ray->side = 0;
		}
		else 
		{
			ray->side_dist_y = ray->side_dist_y + ray->delta_dist_y;
			ray->map_y = ray->map_y + ray->step_y;
			ray->side = 1;
		}
		if (game->config->map.grid[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}
