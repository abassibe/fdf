/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 01:26:00 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/24 03:50:53 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		color(t_param *param, int x, int y)
{
	int		c;

	if (x > y)
		c = x;
	else
		c = y;
	if (param->max_z < 20)
		param->color = 0x0000FF + (c * 0x0C0C00);
	else if (param->max_z < 50)
		param->color = 0x0000FF + (c * 0x050500);
	else if (param->max_z < 100)
		param->color = 0x0000FF + (c * 0x020200);
	else if (param->max_z < 2000)
		param->color = 0x0000FF + (c * 0x010100);
}

static void		pos_x(t_param *param, int x, int y)
{
	int		xf;
	int		yf;

	param->xi = param->xi_b;
	param->yi = param->yi_b;
	xf = param->xi - param->case_size;
	yf = param->yi + param->case_size / param->tilt;
	if (param->map[y][x] > 0)
		param->yi -= param->z_size * param->map[y][x];
	if (param->map[y][x - 1] > 0)
		yf -= param->z_size * param->map[y][x - 1];
	color(param, param->map[y][x - 1], param->map[y][x]);
	algo_bresenham(param, xf, yf);
}

static void		pos_y(t_param *param, int x, int y)
{
	int		xf;
	int		yf;

	param->xi = param->xi_b;
	param->yi = param->yi_b;
	xf = param->xi - param->case_size;
	yf = param->yi - param->case_size / param->tilt;
	if (param->map[y][x] > 0)
		param->yi -= param->z_size * param->map[y][x];
	if (param->map[y - 1][x] > 0)
		yf -= param->z_size * param->map[y - 1][x];
	color(param, param->map[y - 1][x], param->map[y][x]);
	algo_bresenham(param, xf, yf);
}

static int		render_next(t_param *param, int x, int y)
{
	while (x < param->map_max_x)
	{
		if (x > 0 && y < param->map_max_y - 1)
			pos_x(param, x, y);
		if (y > 0 && x > 0)
			pos_y(param, x, y);
		param->xi_b += param->case_size;
		param->yi_b -= param->case_size / param->tilt;
		x++;
	}
	return (x);
}

void			render(t_param *param)
{
	int		x;
	int		y;
	int		xi;
	int		yi;

	y = 0;
	param->xi_b += 20;
	param->yi_b += param->win_length_y -
		(param->map_max_y * (param->case_size / param->tilt));
	xi = param->xi_b;
	yi = param->yi_b;
	while (y < param->map_max_y)
	{
		x = 0;
		x = render_next(param, x, y);
		param->xi_b = xi + param->case_size;
		xi = param->xi_b;
		param->yi_b = yi + (param->case_size / param->tilt);
		yi = param->yi_b;
		y++;
	}
}
