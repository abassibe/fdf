/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:08:47 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/24 05:06:12 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		key_four(int keycode, t_param *param)
{
	if (keycode == 13 && param->tilt > 1)
	{
		mlx_clear_window(param->mlx, param->win);
		clear(param);
		param->yi_b = param->count_dec_y;
		param->xi_b = param->count_dec_x;
		param->tilt--;
		render(param);
		mlx_do_sync(param->mlx);
	}
	if (keycode == 1 && param->tilt < 4)
	{
		mlx_clear_window(param->mlx, param->win);
		clear(param);
		param->yi_b = param->count_dec_y;
		param->xi_b = param->count_dec_x;
		param->tilt++;
		render(param);
		mlx_do_sync(param->mlx);
	}
}

static void		key_three(int keycode, t_param *param)
{
	if (keycode == 116)
	{
		mlx_clear_window(param->mlx, param->win);
		clear(param);
		param->yi_b = param->count_dec_y;
		param->xi_b = param->count_dec_x;
		param->z_size += 1;
		render(param);
		mlx_do_sync(param->mlx);
	}
	if (keycode == 121)
	{
		mlx_clear_window(param->mlx, param->win);
		clear(param);
		param->yi_b = param->count_dec_y;
		param->xi_b = param->count_dec_x;
		param->z_size -= 1;
		render(param);
		mlx_do_sync(param->mlx);
	}
	key_four(keycode, param);
}

static void		key_two(int keycode, t_param *param)
{
	if (keycode == 78)
	{
		mlx_clear_window(param->mlx, param->win);
		clear(param);
		param->yi_b = param->count_dec_y;
		param->xi_b = param->count_dec_x;
		param->case_size -= 5;
		render(param);
		mlx_do_sync(param->mlx);
	}
	if (keycode == 69)
	{
		mlx_clear_window(param->mlx, param->win);
		clear(param);
		param->yi_b = param->count_dec_y;
		param->xi_b = param->count_dec_x;
		param->case_size += 5;
		render(param);
		mlx_do_sync(param->mlx);
	}
	key_three(keycode, param);
}

static void		key_one(int keycode, t_param *param)
{
	if (keycode == 126)
	{
		mlx_clear_window(param->mlx, param->win);
		clear(param);
		param->xi_b = param->count_dec_x;
		param->count_dec_y -= 10;
		param->yi_b = param->count_dec_y;
		render(param);
		mlx_do_sync(param->mlx);
	}
	if (keycode == 125)
	{
		mlx_clear_window(param->mlx, param->win);
		clear(param);
		param->xi_b = param->count_dec_x;
		param->count_dec_y += 10;
		param->yi_b = param->count_dec_y;
		render(param);
		mlx_do_sync(param->mlx);
	}
	key_two(keycode, param);
}

int				key_function(int keycode, t_param *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		mlx_clear_window(param->mlx, param->win);
		clear(param);
		param->yi_b = param->count_dec_y;
		param->count_dec_x -= 10;
		param->xi_b = param->count_dec_x;
		render(param);
		mlx_do_sync(param->mlx);
	}
	if (keycode == 124)
	{
		mlx_clear_window(param->mlx, param->win);
		clear(param);
		param->yi_b = param->count_dec_y;
		param->count_dec_x += 10;
		param->xi_b = param->count_dec_x;
		render(param);
		mlx_do_sync(param->mlx);
	}
	key_one(keycode, param);
	return (0);
}
