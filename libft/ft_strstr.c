/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:19:01 by vgauther          #+#    #+#             */
/*   Updated: 2019/10/14 14:27:19 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i])
	{
		j = i;
		while (s1[j] == s2[j - i] && s1[j] && s2[j - i])
		{
			j++;
		}
		if (s2[j - i] == '\0')
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
