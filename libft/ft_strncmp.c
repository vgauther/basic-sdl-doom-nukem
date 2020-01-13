/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:19:01 by vgauther          #+#    #+#             */
/*   Updated: 2019/10/14 14:26:32 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if ((!s1 && !s2) || n == 0)
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	while ((str1[i] || str2[i]) && str1[i] == str2[i] && i <= n)
	{
		i++;
		if (n == i || (str1 == '\0' && str2 == '\0'))
			return (0);
	}
	return (str1[i] - str2[i]);
}
