/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 03:37:09 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/13 19:45:28 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ft_printf_float/includes/ft_printf.h"

typedef struct		s_param
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		s_l;
	int		endian;
	char	*str_img;
}					t_param;

int		my_key_function(int keycode, t_param *param)
{
	param->endian = 0;
	if (keycode == 53)
		exit (0);
	return (0);
}

int		main(void)
{
	t_param		param;
	int		xi = 100 * 4;
	int		xf = 200 * 4;
	int		yi = 100 * 4;
	int		yf = 200 * 4;
	int		dx = xf - xi;
	int		dy = yf - yi;
	int		cumul = dx / 2;
	int		x = 0;
	int		y = 0;
	double	a, b;
	a = (double) (yf-yi) / (xf-xi);
	b = yi - a * xi;
	x = xi;
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 765, 765, "42");
	/*	while (x++ <= xf)
		{
		y = (int) (a * x + b);
		mlx_pixel_put(param.mlx, param.win, x, y, 0x00FFFFFF);
		}*/
	//	param.img = mlx_new_image(param.mlx, 200, 200);
	//	param.str_img = mlx_get_data_addr(param.img, &param.bpp, &param.s_l, &param.endian);
	/*	x = xi;
		y = yi;
		x = xi + 1;
		while (x++ <= xf)
		{
		cumul += dy;
		if (cumul >= dx)
		{
		cumul -= dx;
		y += 1;
		}
		mlx_pixel_put(param.mlx, param.win, x, y, 0x00FFFFFF);
		}*/
		int i,xinc,yinc;
		x = xi ;
		y = yi ;
		dx = xf - xi ;
		dy = yf - yi ;
		xinc = ( dx > 0 ) ? 1 : -1 ;
		yinc = ( dy > 0 ) ? 1 : -1 ;
		dx = abs(dx) ;
		dy = abs(dy) ;
		mlx_pixel_put(param.mlx, param.win, x, y, 0x00FFFFFF);
		if ( dx > dy )
		{
			cumul = dx / 2 ;
			for ( i = 1 ; i <= dx ; i++ )
			{
				x += xinc ;
				cumul += dy ;
				if ( cumul >= dx )
				{
					cumul -= dx ;
					y += yinc ;
				}
			mlx_pixel_put(param.mlx, param.win, x, y, 0x00FFFFFF);
			}
		}
		else
		{
			cumul = dy / 2 ;
			for ( i = 1 ; i <= dy ; i++ )
			{
				y += yinc ;
				cumul += dx ;
				if ( cumul >= dy )
				{
					cumul -= dy ;
					x += xinc ;
				}
			mlx_pixel_put(param.mlx, param.win, x, y, 0x00FFFFFF);
			}
		}
	//	mlx_put_image_to_window(param.mlx, param.win, param.img, 400, 400);
	mlx_key_hook(param.win, my_key_function, &param);
	mlx_loop(param.mlx);
	return (0);
}
