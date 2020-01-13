/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:55:39 by vgauther          #+#    #+#             */
/*   Updated: 2019/11/29 23:56:43 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_base(char c, int base)
{
	int		i;
	char	*def;

	i = 0;
	def = "0123456789ABCDEF";
	while (i < base)
	{
		if (def[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

unsigned int	ft_atoui_base(const char *str, int base)
{
	unsigned int	ret;

	ret = 0;
	while (*str && *str != ' ')
	{
		if (find_base(ft_toupper(*str), base) != -1)
			ret = (ret * base) + find_base(ft_toupper(*str), base);
		str++;
	}
	return (ret);
}
