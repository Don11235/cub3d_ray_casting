/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:50:26 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/05 01:49:58 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	camera_rotate(t_game_state *game)
{
	double	rot_speed;
	double	tmp;

	rot_speed = game->frame_time * 2.0;
	if (game->keys[123] == 1)
	{
		tmp = game->dir_x;
		game->dir_x = tmp * cos(rot_speed) - game->dir_y * sin(rot_speed);
		game->dir_y = tmp * sin(rot_speed) + game->dir_y * cos(rot_speed);
		tmp = game->plane_x;
		game->plane_x = tmp * cos(rot_speed) - game->plane_y * sin(rot_speed);
		game->plane_y = tmp * sin(rot_speed) + game->plane_y * cos(rot_speed);
	}
	if (game->keys[124] == 1)
	{
		tmp = game->dir_x;
		game->dir_x = tmp * cos(-rot_speed) - game->dir_y * sin(-rot_speed);
		game->dir_y = tmp * sin(-rot_speed) + game->dir_y * cos(-rot_speed);
		tmp = game->plane_x;
		game->plane_x = tmp * cos(-rot_speed) - game->plane_y * sin(-rot_speed);
		game->plane_y = tmp * sin(-rot_speed) + game->plane_y * cos(-rot_speed);
	}
}
