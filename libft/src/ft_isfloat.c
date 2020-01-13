/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:55:39 by vgauther          #+#    #+#             */
/*   Updated: 2019/11/29 23:57:12 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isfloat(char *str)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 || str[i] == '.')
		{
			if (str[i] == '.')
				count++;
		}
		else
			return (0);
		if (count > 1)
			return (0);
		i++;
	}
	return (1);
}
