/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:55:39 by vgauther          #+#    #+#             */
/*   Updated: 2019/11/29 23:59:38 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	unsigned int	l;
	char			*str;

	if (s != NULL && f != NULL)
	{
		i = 0;
		l = ft_strlen(s);
		str = ft_strnew(l);
		while (i < l)
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
