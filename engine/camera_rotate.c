/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:50:26 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/04 00:48:21 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	camera_rotate(t_game_state *game)
{
	double	rot_speed;
	double	old_dir_x;
	double	od_px;

	rot_speed = game->frame_time * 0.5;
	if (game->keys[123] == 1)
	{
		old_dir_x = game->dir_x;
		game->dir_x = old_dir_x * cos(rot_speed) - game->dir_y * sin(rot_speed);
		game->dir_y = old_dir_x * sin(rot_speed) + game->dir_y * cos(rot_speed);
		od_px = game->plane_x;
		game->plane_x = od_px * cos(rot_speed) - game->plane_y * sin(rot_speed);
		game->plane_y = od_px * sin(rot_speed) + game->plane_y * cos(rot_speed);
	}
	if (game->keys[124] == 1)
	{
		old_dir_x = game->dir_x;
		game->dir_x = old_dir_x * cos(-rot_speed) - game->dir_y
			* sin(-rot_speed);
		game->dir_y = old_dir_x * sin(-rot_speed) + game->dir_y
			* cos(-rot_speed);
		od_px = game->plane_x;
		game->plane_x = od_px * cos(-rot_speed) - game->plane_y
			* sin(-rot_speed);
		game->plane_y = od_px * sin(-rot_speed) + game->plane_y
			* cos(-rot_speed);
	}
}
