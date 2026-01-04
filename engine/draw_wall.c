/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:21:20 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/03 21:26:43 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	init_tex_pos(t_draw *draw)
{
	draw->tex_pos = (draw->draw_start - 1080.0 / 2.0 + draw->line_height / 2.0)
		* draw->step;
}

void	draw_wall_column(t_game_state *game, t_ray *ray, t_draw *draw, int x)
{
	double			wall_x;
	int				texture_x;
	int				texture_y;
	unsigned int	color;

	draw->step = 1.0 * draw->texture.height / draw->line_height;
	init_tex_pos(draw);
	while (draw->draw_start < draw->draw_end)
	{
		texture_y = (int)draw->tex_pos;
		draw->tex_pos += draw->step;
		if (texture_y < 0)
			texture_y = 0;
		if (texture_y >= draw->texture.height)
			texture_y = draw->texture.height - 1;
		if (ray->side == 0)
			wall_x = game->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
		else
			wall_x = game->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
		wall_x = wall_x - floor(wall_x);
		texture_x = (int)(wall_x * draw->texture.width);
		color = my_mlx_pixel_get(&draw->texture.img_xpm, texture_x, texture_y);
		my_mlx_pixel_put(&game->img, x, draw->draw_start, color);
		draw->draw_start++;
	}
}

void	draw_wall(t_game_state *game, t_ray *ray, t_draw *draw, int x)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
	{
		draw->texture = game->textures[WE];
		draw_wall_column(game, ray, draw, x);
	}
	else if (ray->side == 0 && ray->ray_dir_x < 0)
	{
		draw->texture = game->textures[EA];
		draw_wall_column(game, ray, draw, x);
	}
	else if (ray->side == 1 && ray->ray_dir_y > 0)
	{
		draw->texture = game->textures[SO];
		draw_wall_column(game, ray, draw, x);
	}
	else if (ray->side == 1 && ray->ray_dir_y < 0)
	{
		draw->texture = game->textures[NO];
		draw_wall_column(game, ray, draw, x);
	}
}
