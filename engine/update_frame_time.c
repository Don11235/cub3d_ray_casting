/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:28:32 by mben-cha          #+#    #+#             */
/*   Updated: 2025/12/29 14:33:39 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void    update_frame_time(t_game_state *game)
{
    game->oldTime = game->time;
    game->time = getTicks();
    game->frameTime = (game->time - game->oldTime) / 100;
}