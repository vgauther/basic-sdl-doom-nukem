/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memreg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:55:39 by vgauther          #+#    #+#             */
/*   Updated: 2019/11/29 23:57:50 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memreg3(char ***s)
{
	int i;
	int j;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			j = 0;
			while (s[i][j])
			{
				free(s[i][j]);
				s[i][j] = NULL;
				j++;
			}
			free(s[i]);
			s[i] = NULL;
			i++;
		}
		free(s);
	}
	s = NULL;
}

void	ft_memreg(char **s)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			free(s[i]);
			s[i] = NULL;
			i++;
		}
		free(s);
		s = NULL;
	}
}
