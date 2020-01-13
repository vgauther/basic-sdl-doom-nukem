/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:19:01 by vgauther          #+#    #+#             */
/*   Updated: 2019/10/14 14:26:51 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1[i] && i < len)
	{
		j = i;
		while (s1[j] == s2[j - i] && s1[j] && s2[j - i] && j < len)
		{
			j++;
		}
		if (s2[j - i] == '\0')
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
