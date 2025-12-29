/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:54:01 by mben-cha          #+#    #+#             */
/*   Updated: 2025/12/29 20:54:43 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void    draw_floor_ceiling(t_game_state *game)
{
    int i;
    int j;

    i = 0;
    while (i < 1920)
    {
        j = 0;
        while (j < 1080)
        {
            if (j < 1080 / 2)
                my_mlx_pixel_put(&game->img, i, j, game->ceiling_c);
            else
                my_mlx_pixel_put(&game->img, i, j, game->floor_c);
            j++;
        }
        i++;
    }
}