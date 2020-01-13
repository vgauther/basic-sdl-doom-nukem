/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:55:39 by vgauther          #+#    #+#             */
/*   Updated: 2019/11/29 23:59:35 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	size_t	i;
	size_t	l;
	char	*str;

	if (s != NULL && f != NULL)
	{
		i = 0;
		l = ft_strlen(s);
		str = ft_strnew(l);
		while (i < l)
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
