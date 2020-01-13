/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_s1s2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:19:01 by vgauther          #+#    #+#             */
/*   Updated: 2019/10/14 14:25:48 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_free_s1s2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!(s1 && s2))
		return (NULL);
	j = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		str[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	free(s1);
	free(s2);
	str[j] = '\0';
	return (str);
}
