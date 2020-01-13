/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:55:39 by vgauther          #+#    #+#             */
/*   Updated: 2019/11/29 23:57:19 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				check_negatif(int n, long *mem, int *sign)
{
	if (n < 0)
	{
		*mem = -n;
		*sign = 1;
	}
	else
		*mem = n;
}

void				ft_light_itoa(int n, char *str)
{
	int				sign;
	long			mem;
	unsigned int	nb;
	int				i;

	i = 1;
	sign = 0;
	check_negatif(n, &mem, &sign);
	nb = (unsigned int)mem;
	while (mem /= 10)
		i++;
	str[i + sign] = '\0';
	i--;
	while (i + sign > -1)
	{
		str[i + sign] = (nb % 10 + 48);
		nb = nb / 10;
		i--;
	}
	if (sign == 1)
		str[0] = '-';
}

char				*ft_itoa(int n)
{
	char			*str;
	int				save;
	int				neg;
	int				i;

	save = n;
	neg = (n < 0 ? -1 : 1);
	i = 1 + (n < 0);
	while (n /= 10)
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i--] = '\0';
	str[i--] = neg * (save % 10) + 48;
	while (save /= 10)
		str[i--] = neg * (save % 10) + 48;
	if (neg < 0)
		str[i] = '-';
	return (str);
}
