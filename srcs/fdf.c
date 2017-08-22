/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:40:26 by abassibe          #+#    #+#             */
/*   Updated: 2017/07/26 06:44:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		init_lst(t_param *param)
{
	param->map = NULL;
	param->mlx = NULL;
	param->win = NULL;
	param->map_max_x = 0;
	param->map_max_y = 0;
	param->win_max_x = 0;
	param->win_max_y = 0;
	param->win_length_x = 0;
	param->win_length_y = 0;
	param->title = NULL;
	param->x = 0;
	param->y = 0;
	param->xi = 0;
	param->xi_b = 0;
	param->yi = 0;
	param->yi_b = 0;
	param->xinc = 0;
	param->yinc = 0;
	param->case_size = 15;
	param->z_size = 1;
	param->max_z = 0;
	param->count_dec_x = 0;
	param->count_dec_y = 0;
	param->color = 0;
	param->tilt = 2;
}

t_param			*crea_lst(void)
{
	t_param		*new;

	new = (t_param *)malloc(sizeof(t_param));
	init_lst(new);
	return (new);
}

static void		get_file_name(t_param *param, char *str)
{
	int			i;
	int			len;

	i = 0;
	len = (int)ft_strlen(str) - 1;
	while (str[len] != '/' && len > 0)
	{
		len--;
		i++;
	}
	if (str[len] == '/')
		len++;
	param->title = ft_strnew(i);
	i = 0;
	while (str[len])
		param->title[i++] = str[len++];
}

static void		usage(void)
{
	write(1, "For zoom function use pavnum + and pavnum -.\n", 45);
	write(1, "For move function use directional arrow.\n", 41);
	write(1, "For increase/decrease z value use page up and page down.\n", 57);
	write(1, "For tilt function use w and s.\n", 31);
	exit(0);
}

int				main(int ac, char **av)
{
	t_param		*param;
	int			fd;

	fd = 0;
	if (ac != 2)
	{
		write(2, "Usage : ./fdf <filename>\n        ./fdf help\n", 44);
		return (0);
	}
	if (ft_strcmp("help", av[1]) == 0)
		usage();
	param = crea_lst();
	get_file_name(param, av[1]);
	get_map(av[1], param, fd);
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, param->win_length_x,
			param->win_length_y, param->title);
	render(param);
	mlx_key_hook(param->win, &key_function, param);
	mlx_loop(param->mlx);
	return (0);
}
