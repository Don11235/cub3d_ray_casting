/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:15:43 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/03 19:58:27 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	compute_wall(t_ray *ray, t_draw *draw)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	draw->line_height = (int)(1080 / ray->perp_wall_dist);
	draw->draw_start = 1080 / 2 - draw->line_height / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = 1080 / 2 + draw->line_height / 2;
	if (draw->draw_end >= 1080)
		draw->draw_end = 1080 - 1;
}
