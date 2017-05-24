/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:54:25 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/05 05:54:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		c;
	size_t	k;

	c = 0;
	k = 0;
	while (s1[c] != '\0')
		c++;
	while (k != n && s2[k] != '\0')
	{
		s1[c] = s2[k];
		c++;
		k++;
	}
	s1[c] = '\0';
	return (s1);
}
