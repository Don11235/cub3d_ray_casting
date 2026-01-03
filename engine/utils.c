/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:10:53 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/03 17:06:12 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
#include "../include/minilibx/mlx.h"

double	getTicks(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}

int	is_inside_map(t_game_state *game, int y, int x)
{
	if (y < 0 || y >= game->config->map.height)
		return (0);
	if (x < 0 || x >= game->config->map.width)
		return (0);
	return (1);
}

void	is_valid_texture(t_game_state *game, int index, void *img)
{
	int i;

	i = 0;
	if (!img)
	{
		while (i < index)
			mlx_destroy_image(game->mlx, game->textures[i++].img_xpm.img);
		mlx_destroy_image(game->mlx, game->img.img);
		mlx_destroy_window(game->mlx, game->mlx_win);
		ft_free_config(game->config);
		write(2, "Failed to load texture\n", 23);
		exit(1);
	}
}