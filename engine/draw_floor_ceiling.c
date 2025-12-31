/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:54:01 by mben-cha          #+#    #+#             */
/*   Updated: 2025/12/30 23:45:24 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void    draw_floor_ceiling(t_game_state *game)
{
    int i;
    int j;

    i = 0;
    printf("Helo-------------%p\n", &game->img);
    printf("ceil: %d\n", game->ceiling_c);
    printf("floor: %d\n", game->floor_c);
    while (i < 1920)
    {
        j = 0;
        while (j < 1080)
        {
            if (j < 1080 / 2)
            {
                printf("%d\n", j);
                my_mlx_pixel_put(&game->img, i, j, game->ceiling_c);
                
            }
            else
            {
                printf("%d\n", j);
                my_mlx_pixel_put(&game->img, i, j, game->floor_c);
            }
            j++;
        }
        i++;
    }
}