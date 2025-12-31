/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:44:39 by mben-cha          #+#    #+#             */
/*   Updated: 2025/12/30 23:42:20 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
#include "../include/minilibx/mlx.h"

void run_engine(t_config *config)
{
    t_game_state	game;

	init_game(&game, config);
	mlx_hook(game.mlx_win, 2, 0, keyPress, &game);
    mlx_hook(game.mlx_win, 3, 0, keyRelease, &game);
    mlx_hook(game.mlx_win, 17, 0, Close, &game);
    mlx_loop_hook(game.mlx, redraw, &game);
    mlx_loop(game.mlx);
}