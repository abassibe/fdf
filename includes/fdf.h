/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:59:39 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/24 05:08:10 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../includes/libft.h"
# include "../ressources/minilibx/mlx.h"

# include <stdio.h>

typedef struct		s_param
{
	int				**map;
	void			*mlx;
	void			*win;
	int				map_max_x;
	int				map_max_y;
	int				win_max_x;
	int				win_max_y;
	int				win_length_x;
	int				win_length_y;
	char			*title;
	int				x;
	int				y;
	int				xi;
	int				xi_b;
	int				yi;
	int				yi_b;
	int				xinc;
	int				yinc;
	int				case_size;
	int				z_size;
	int				max_z;
	int				count_dec_x;
	int				count_dec_y;
	int				color;
	int				tilt;
}					t_param;

void				get_map(char *str, t_param *param, int fd);

void				render(t_param *param);

int					key_function(int keycode, t_param *param);

void				algo_bresenham(t_param *param, int xf, int yf);

t_param				*crea_lst(void);

void				clear(t_param *param);

#endif
