/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:03:50 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/22 18:29:39 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		count_points(char *str)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0' && str[i] != ' ')
			ret++;
		while (str[i] != '\0' && str[i] != ' ')
			i++;
	}
	return (ret);
}

static void		lenght_alloc(char *str, t_param *param)
{
	int		fd;
	char	*tmp;
	int		i;

	i = 0;
	if (!(fd = open(str, O_RDONLY)))
	{
		write(2, "An error occurred while opening file.\n", 38);
		exit(0);
	}
	while (get_next_line(fd, &tmp))
	{
		if (param->map_max_y == 0)
		{
			param->map_max_x = count_points(tmp);
			if (param->map_max_x == 0)
			{
				write(2, "It seems like the file is empty.\n", 33);
				exit(0);
			}
		}
		param->map_max_y++;
	}
	param->map = (int **)malloc(param->map_max_y);
	close(fd);
}

static void		length_win(t_param *param)
{
	param->win_length_y = (35 + param->z_size) * param->map_max_y;
	if (param->win_length_y > 1280)
		param->win_length_y = 1280;
	if (param->win_length_y < 400)
		param->win_length_y = 400;
	param->win_length_x = 30 * param->map_max_x;
	if (param->win_length_x > 1600)
		param->win_length_x = 1600;
	if (param->win_length_x < 400)
		param->win_length_x = 400;
	if (param->map_max_y >= 100 || param->map_max_x >= 100)
		param->case_size = 5;
	if (param->map_max_y >= 200 || param->map_max_x >= 200)
		param->case_size = 3;
	if (param->map_max_y >= 300 || param->map_max_x >= 300)
		param->case_size = 2;
}

void			fill_tab(t_param *param, char *str, int i)
{
	int		c;
	int		j;

	c = 0;
	j = 0;
	while (str[c] && j < param->map_max_x)
	{
		while (str[c] == ' ')
			c++;
		if (str[c] >= '0' && str[c] <= '9')
		{
			param->map[i][j++] = ft_atoi(&str[c]);
			if (param->map[i][j - 1] > param->max_z)
				param->max_z = param->map[i][j - 1];
		}
		while (str[c] != ' ')
		{
			c++;
			if (str[c] == '\0')
				break ;
		}
	}
}

void			get_map(char *str, t_param *param, int fd)
{
	int		i;
	char	**s;

	i = 0;
	lenght_alloc(str, param);
	s = (char **)malloc(param->map_max_y + 1);
	if (!(fd = open(str, O_RDONLY)))
	{
		write(2, "An error occurred while opening file.\n", 38);
		exit(0);
	}
	while (get_next_line(fd, &s[i]))
	{
		param->map[i] = (int *)malloc(sizeof(int) * param->map_max_x);
		fill_tab(param, s[i], i);
		i++;
	}
	length_win(param);
	close(fd);
	param->x = (param->win_length_x / 2) - (param->map_max_x / 2);
	param->y = (param->win_length_y / 2) - (param->map_max_y / 2);
}
