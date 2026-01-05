/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:50:51 by mohkhald          #+#    #+#             */
/*   Updated: 2026/01/05 19:04:22 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdnoreturn.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
}				t_texture;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_player
{
	int			x;
	int			y;
	char		dire;
}				t_player;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
}				t_map;

typedef struct s_config
{
	t_texture	textures;
	t_color		floor;
	t_color		ceil;
	t_map		map;
	t_player	player;
	bool		valid;
	bool		floor_set;
	bool		ceil_set;
}				t_config;

typedef enum s_tex_id
{
	EA,
	NO,
	SO,
	WE,
}				t_tex_id;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_tex
{
	t_data		img_xpm;
	int			width;
	int			height;
}				t_tex;

typedef struct s_game_state
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	t_data		img;
	void		*mlx;
	void		*mlx_win;
	double		old_time;
	double		time;
	double		frame_time;
	t_tex		textures[4];
	int			keycode;
	double		move_speed;
	double		rot_speed;
	int			keys[127];
	int			floor_c;
	int			ceiling_c;
	t_config	*config;
}				t_game_state;

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
}				t_ray;

typedef struct s_draw
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		step;
	double		tex_pos;
	t_tex		texture;
}				t_draw;

/*Parse functions*/

/*main config*/
bool			ft_valid_file(char *file);
int				ft_open_file(char *path);
void			ft_parse_file(char *arr, t_config *config);
t_config		*ft_init_config(void);

/*map functions*/
char			**ft_malloc_map_grid(int height);
bool			ft_is_map_line(char *line);
bool			ft_fill_map(char **grid, char *line, int row);
bool			ft_config_is_complete(t_config *config);
bool			ft_valid_map(t_config *config);
bool			ft_check_map_gaps(t_map *map, t_player *player);
int				ft_count_map_l(char *arr);
bool			ft_is_player_char(char c);

/*textures*/
bool			ft_is_texture_line(char *line);
void			ft_fill_textu_path(t_config *config, char *line);
char			*ft_extract_path(char *line);
bool			ft_is_valid_path(char *line);

/*utils*/
char			*ft_skip_space(char *line);
void			ft_free_config(t_config *config);
void			ft_free_split(char **s);
void			ft_free_error(char *msg, t_config *config);
bool			ft_is_numeric(char **s);

/*color*/
bool			ft_is_color_line(char *line);
void			ft_fill_color_conf(t_config *config, char *line);
int				*ft_handel_rgb(char *s);
bool			ft_is_valid_rgb(int r, int g, int b);

/* Graphics / Rendering functions */

double			get_ticks(void);
void			init_game(t_game_state *game, t_config *config);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_data *data, int x, int y);
void			camera_move(t_game_state *game);
void			camera_rotate(t_game_state *game);
void			compute_wall(t_ray *ray, t_draw *draw);
void			dda(t_game_state *game, t_ray *ray);
void			draw_wall(t_game_state *game, t_ray *ray, t_draw *draw, int x);
void			init_ray(t_game_state *game, t_ray *ray, int x);
void			update_frame_time(t_game_state *game);
void			draw_floor_ceiling(t_game_state *game);
void			render_walls(t_game_state *game);
int				redraw(t_game_state *game);
int				key_press(int keycode, t_game_state *game);
int				key_release(int keycode, t_game_state *game);
int				ft_close_game(t_game_state *game);
void			run_engine(t_config *config);
int				is_inside_map(t_game_state *game, int y, int x);
void			is_valid_texture(t_game_state *game, int index, void *img);
void	ft_draw_minimap(t_game_state *game);
#endif
