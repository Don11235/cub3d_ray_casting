#ifndef CUB_H
# define CUB_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
#include <stdnoreturn.h>
# include <string.h>
#include <sys/errno.h>
# include <unistd.h>
#include <math.h>
#include <sys/time.h>

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
}	t_tex_id;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct	s_tex
{
	t_data	img_xpm;
	int		width;
	int		height;
}	t_tex;

typedef struct	s_game_state
{
    double		posX;
    double		posY;
    double		dirX;
    double		dirY;
    double		planeX;
    double		planeY;
    t_data		img;
    void		*mlx;
    void		*mlx_win;
    double		oldTime;
    double		time; 
    double		frameTime;
	t_tex		textures[4];
    int			keycode;
    double		moveSpeed;
    double		rotSpeed;
    int			keys[127];
	int			floor_c;
	int			ceiling_c;
	t_config	*config;
}	t_game_state;

typedef struct	s_ray
{
	double	cameraX;
    double	rayDirX;
    double	rayDirY;
    int		mapX;
    int		mapY;
    double	sideDistX;
    double	sideDistY;
    double	deltaDistX;
    double	deltaDistY;
    int		stepX;
    int		stepY;
    int		hit;
    int		side;
    double	perpWallDist;
}	t_ray;

typedef struct	s_draw
{
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	step;
	double	texPos;
	t_tex	texture;
}	t_draw;

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

double			getTicks(void);
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
int				keyPress(int keycode, t_game_state *game);
int				keyRelease(int keycode, t_game_state *game);
int				Close(t_game_state *game);
void			run_engine(t_config *config);
int				is_inside_map(t_game_state *game, int y, int x);

#endif
