/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:59:52 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/05 19:11:28 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
#include "../include/minilibx/mlx.h"

int	redraw(t_game_state *game)
{
	update_frame_time(game);
	camera_move(game);
	camera_rotate(game);
	draw_floor_ceiling(game);
	render_walls(game);
	//ft_draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	return (0);
}
