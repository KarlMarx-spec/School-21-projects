/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfeijoa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:58:18 by wfeijoa           #+#    #+#             */
/*   Updated: 2020/09/22 19:01:29 by wfeijoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MAPSYM "NWES201"
# define MAPSYM2 "NWES201 \n"
# define MAPPAR "NWESRFC\n"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480



typedef struct	s_game
{
	
	char	**map;
	int		max_size;
	int		map_x;
	int		map_y;
	int		current_size;
	int		width;
	double	*dist;
	int		height;
	int		num_param;
	char	*text_E_filename;
	char	*text_S_filename;
	char	*text_N_filename;
	char	*text_W_filename;
	char	*text_SP_filename;
	int 	worldMap[mapWidth][mapHeight];
	void    *mlx;
    void    *win;
	double		hx;
	double		hy;
	double		wx;
	double		wy;
	int			cc;
	void *south;//replace to img in t_data
	void *east;
	void *west;
	void *north;
	char *sp_tx;
	char *s_tx;
	char *n_tx;
	char *w_tx;
	char *e_tx;
	int	floor;
	int celling;
	int text_w;
	int text_h;
}				t_game;

typedef struct	s_sprites
{
	double x;
	double y;
	double dist;
}				t_sprites;

typedef struct	s_player
{
	double x;
	double y;
	double a;
	double s;
	double fov;
	double pov;
}				t_player;

typedef struct  s_data {
    void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	char	*addr;
}               t_data;


typedef struct 	s_all
{
	t_player *tp;
	t_game		*t;
	t_data		*ts;
	t_data		*tn;
	t_data		*te;
	t_data		*tw;
	t_sprites	sprt[1000];
	t_data		*tfloor;
	t_data		*t_data_gen;
	t_data		*t_data_tex;
	t_sprites	*sp;
}				t_all;

#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
int				ft_putstr(char *s);
void			read_map2(int fd, t_all *al);
int				ft_move(int key, t_all *al);
int				ft_redraw(t_all *al);
int				key_closing(int key, t_all *al);
void			my_mlx_pixel_put(t_data *td, int x, int y, int color);
unsigned int	my_mlx_img_clr(t_data *ts, int x, int y);
void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
//int				ft_move(int key, t_all *al);
void			change_pl_pos(t_all *al, short way);
void			draw_wall(t_all *al, char s, int j, int count, int wall_height);
double			horizontal(t_all *al, float alpha);
double			vertical(t_all *al, float alpha);
void			ft_open(t_all *al, char *file);
void			error(char *s);
#endif