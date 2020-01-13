/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:19:01 by vgauther          #+#    #+#             */
/*   Updated: 2019/10/14 14:21:55 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr(int nb)
{
	unsigned int	i;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	i = nb;
	if (i / 10 >= 1)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}
