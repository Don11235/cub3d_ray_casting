/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:28:32 by mben-cha          #+#    #+#             */
/*   Updated: 2026/01/04 16:48:41 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	update_frame_time(t_game_state *game)
{
	game->old_time = game->time;
	game->time = get_ticks();
	game->frame_time = (game->time - game->old_time) / 100;
}
