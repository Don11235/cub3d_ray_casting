/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:10:53 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/01 16:32:32 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

double  getTicks(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}

int is_inside_map(t_game_state *game, int y, int x)
{
    if (y < 0 || y >= game->config->map.height)
        return (0);
    if (x < 0 || x >= game->config->map.width)
        return (0);
    return (1);
}