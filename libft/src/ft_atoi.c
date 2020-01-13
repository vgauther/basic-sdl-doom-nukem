/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:55:39 by vgauther          #+#    #+#             */
/*   Updated: 2019/11/29 23:56:37 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_caract(const char *str)
{
	int				i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' && ft_isdigit(str[i + 1]) != 0)
		i++;
	return (i);
}

unsigned int		ft_atou(const char *str)
{
	int				i;
	unsigned int	res;

	i = ft_caract(str);
	res = 0;
	if (ft_strcmp(str, "4294967295") == 0)
		res = 4294967295;
	else
	{
		while (ft_isdigit(str[i]) != 0)
		{
			res = res * 10;
			res = res + (str[i] - 48);
			i++;
		}
	}
	return (res);
}

int					ft_atoi(const char *str)
{
	int				i;
	int				res;
	int				neg;

	i = ft_caract(str);
	neg = 0;
	res = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]) != 0)
	{
		neg++;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		res = res * 10;
		res = res + (str[i] - 48);
		i++;
	}
	return (neg == 1 ? -res : res);
}
