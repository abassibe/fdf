/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 02:59:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/30 03:00:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clean_img(t_param *param)
{
	int		i;

	i = 0;
	while (i < (param->win_length_x * 4) * param->win_length_y)
	{
		param->img[i] = 0x00;
		param->img[i + 1] = 0x00;
		param->img[i + 2] = 0x00;
		param->img[i + 3] = 0;
		i += 4;
	}
}

void	draw_img(t_param *param)
{
	int		i;

	i = (param->x * 4) + (param->y * param->sl);
	if (i > ((param->win_length_x * 4) + (param->win_length_y * param->sl)))
		return ;
	param->img[i] = param->color >> 16;
	param->img[i + 1] = (param->color << 8) >> 16;
	param->img[i + 2] = (param->color << 16) >> 16;
	param->img[i + 3] = 0;
}
