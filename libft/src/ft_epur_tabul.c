/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_tabul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:55:39 by vgauther          #+#    #+#             */
/*   Updated: 2019/11/29 23:56:53 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			things(const char *src)
{
	int		hint;
	int		a;

	a = -1;
	hint = 0;
	while (*(src + ++a) != '\0')
	{
		if (*(src + a) == '\t')
			hint++;
	}
	return (hint);
}

char		*ft_epur_tabul(const char *src)
{
	int		count;
	int		a;
	char	*ret;

	a = 0;
	count = -1;
	ret = (char *)ft_memalloc(sizeof(char) * (ft_strlen(src)
		- things(src) + 1));
	if (ret == NULL)
		return (NULL);
	while (*(src + ++count + a) != '\0')
	{
		while (*(src + count + a) == '\t')
			a++;
		*(ret + count) = *(src + count + a);
	}
	return (ret);
}
