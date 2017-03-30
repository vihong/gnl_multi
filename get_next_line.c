/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 00:15:07 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/30 16:29:41 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_s(char *stock)
{
	int		i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		clean_stock(char **line, char **stock)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*stock);
	*line = ft_strsub(*stock, 0, check_s(*stock));
	tmp = *stock;
	*stock = ft_strsub(*stock, check_s(*stock) + 1, len - check_s(*stock));
	free(tmp);
	return (1);
}

int		empty_s(char **line, char **stock)
{
	*line = *stock;
	*stock = NULL;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*stock;
	int			ret;

	if (!stock)
		stock = ft_strdup("");
	ret = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		stock = ft_strjoin_gnl(stock, buf);
		if (check_s(stock) != -1)
			return (clean_stock(line, &stock));
	}
	if (ret == -1)
		return (-1);
	if (check_s(stock) != -1)
		return (clean_stock(line, &stock));
	if (ft_strlen(stock) != 0)
		return (empty_s(line, &stock));
	return (0);
}
