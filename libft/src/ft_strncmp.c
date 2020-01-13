/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:55:39 by vgauther          #+#    #+#             */
/*   Updated: 2019/11/29 23:59:43 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				diff;

	i = 0;
	if (!s1 || !s2 || n < 1)
		return (0);
	while (s1[i] && i < n)
	{
		diff = ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (diff != 0)
			return (diff);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
