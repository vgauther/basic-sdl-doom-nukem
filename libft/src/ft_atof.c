/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:55:22 by vgauther          #+#    #+#             */
/*   Updated: 2019/11/29 23:55:23 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_virgule(const char *str, double value)
{
	double	cpt;
	double	virgule;

	cpt = 1;
	if (*str == '.')
	{
		str++;
		virgule = 0;
		while ((*str <= '9') && (*str >= '0'))
		{
			virgule = (virgule * 10) + (*str - '0');
			cpt = cpt * 10;
			str++;
		}
		value = value - (virgule / cpt);
	}
	return (value);
}

double		ft_atof(const char *str)
{
	int		is_negative;
	double	value;

	is_negative = 0;
	value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' ||
		*str == '\v' || *str == '\r')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		value = (value * 10) - (*str - '0');
		str++;
	}
	value = ft_virgule(str, value);
	if (!is_negative)
		value = -value;
	return (value);
}
