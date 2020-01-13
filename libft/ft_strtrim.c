/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:19:01 by vgauther          #+#    #+#             */
/*   Updated: 2019/10/14 14:27:29 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_blank(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (-1);
	return (i);
}

static int	ft_rev_blank(char const *s)
{
	int j;

	j = 0;
	while (s[j])
		j++;
	j--;
	while (s[j] == ' ' || s[j] == ',' || s[j] == '\n' || s[j] == '\t')
		j--;
	return (j);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		n;

	n = 0;
	if (!s)
		return (NULL);
	i = ft_blank(s);
	j = ft_rev_blank(s);
	if (!(str = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	if (i == -1)
	{
		str[0] = '\0';
		return (str);
	}
	while (i <= j)
	{
		str[n] = s[i];
		n++;
		i++;
	}
	str[n] = '\0';
	return (str);
}
