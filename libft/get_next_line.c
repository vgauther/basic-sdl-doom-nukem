/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:19:01 by vgauther          #+#    #+#             */
/*   Updated: 2019/10/30 16:42:07 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			read_from_fd_into_stock(int const fd, char **stock)
{
	static char	buff[BUFF_SIZE + 1] = { ENDL };
	int			read_bytes;
	char		*nstr;

	read_bytes = read(fd, buff, BUFF_SIZE);
	if (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		nstr = ft_strjoin(*stock, buff);
		if (!nstr)
			return (-1);
		free(*stock);
		*stock = nstr;
	}
	return (read_bytes);
}

static void	set_stock(char **stock, char **endl_index)
{
	*endl_index = ft_strdup(*endl_index + 1);
	free(*stock);
	*stock = *endl_index;
}

int			get_next_line(int const fd, char **line)
{
	static char	*stock = NULL;
	char		*endl_index;
	int			ret;

	if (!stock && (stock = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	endl_index = ft_strchr(stock, ENDL);
	while (endl_index == NULL)
	{
		ret = read_from_fd_into_stock(fd, &stock);
		if (ret == 0)
		{
			if ((endl_index = ft_strchr(stock, '\0')) == stock)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			endl_index = ft_strchr(stock, ENDL);
	}
	*line = ft_strsub(stock, 0, endl_index - stock);
	if (!*line)
		return (-1);
	set_stock(&stock, &endl_index);
	return (1);
}
