/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:19:01 by vgauther          #+#    #+#             */
/*   Updated: 2019/10/14 14:20:03 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*ft_execp(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	return (ft_strdup("-2147483648"));
}

static char	*ft_int_to_str(int i, int nb, int neg, char *str)
{
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		nb;
	int		neg;
	char	*str;

	str = NULL;
	i = 0;
	neg = 0;
	if (n == -2147483648 || n == 0)
		return (ft_execp(n));
	if (n < 0)
	{
		n = n * -1;
		neg = 1;
		i++;
	}
	nb = n;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	str = ft_int_to_str(i, nb, neg, str);
	return (str);
}
