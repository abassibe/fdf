/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 03:37:09 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/08 17:33:31 by abassibe         ###   ########.fr       */
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
	int		x;
	int		y;
	int		color;
	int		color_save;
	int		color3;
	int		color4;
	long int		test;

	color = 0x0000FF00;
	color3 = 0;
	color4 = 0;
	y = 0;
	test = 0;
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 765, 765, "42");
	while (y < 765)
	{
		x = 0;
		color_save = color;
		while (x < 765)
		{
			mlx_pixel_put(param.mlx, param.win, x, y, color);
			if (x % 3 == 0)
				color += 0x00000001;
			if (color3 < 255)
				if (x % 3 == 0)
				{
					color -= 0x00000100;
					color3++;
				}
			x++;
		}
		color = color_save;
		if (y % 3 == 0)
			color += 0x00010000;
		if (color4 < 255)
			if (y % 3 == 0)
			{
				color -= 0x00000100;
				color4++;
			}
		y++;
	}
	param.img = mlx_new_image(param.mlx, 200, 200);
	param.str_img = mlx_get_data_addr(param.img, &param.bpp, &param.s_l, &param.endian);
	x = param.s_l * 100 - 1;
	while (test < 1600)
	{
		param.str_img[x] = 0;
		param.str_img[x + 1] = 255;
		param.str_img[x + 2] = 255;
		param.str_img[x + 3] = 255;
		x += 4;
		test++;
	}
//	mlx_put_image_to_window(param.mlx, param.win, param.img, 400, 400);
	mlx_key_hook(param.win, my_key_function, &param);
	mlx_loop(param.mlx);
	return (0);
}
