/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:14:57 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/30 02:59:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			clear(t_param *param)
{
	param->x = 0;
	param->y = 0;
	param->xi = 0;
	param->xi_b = 0;
	param->yi = 0;
	param->yi_b = 0;
	param->xinc = 0;
	param->yinc = 0;
}

static void		algo_dy_sup_dx(t_param *param, int dx, int dy)
{
	int		i;
	int		cumul;

	cumul = dy / 2;
	i = 1;
	while (i++ <= dy)
	{
		param->y += param->yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			param->x += param->xinc;
		}
		draw_img(param);
	}
}

static void		algo_dx_sup_dy(t_param *param, int dx, int dy)
{
	int		i;
	int		cumul;

	cumul = dx / 2;
	i = 1;
	while (i++ <= dx)
	{
		param->x += param->xinc;
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			param->y += param->yinc;
		}
		draw_img(param);
	}
}

void			algo_bresenham(t_param *param, int xf, int yf)
{
	int		dx;
	int		dy;

	dx = xf - param->xi;
	dy = yf - param->yi;
	param->x = param->xi;
	param->y = param->yi;
	param->xinc = (dx > 0) ? 1 : -1;
	param->yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	if (dx > dy)
		algo_dx_sup_dy(param, dx, dy);
	else
		algo_dy_sup_dx(param, dx, dy);
}
