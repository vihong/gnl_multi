/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 00:15:07 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/24 04:14:36 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define	BUFF_SIZE 10000


int		stock_checker(char* stock)
{
	int		i = 0;
	
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}


int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char*	stock = "";		
	int				ret = 0;


	ret = read(fd, buf, BUFF_SIZE);
//	printf("%d\n", ret);
	buf[ret] = '\0';


	stock = ft_strjoin(stock, ft_strdup(buf));

//	printf("1) %s\n", stock);


	if (stock_checker(stock) != -1)
	{
	//	printf("2) %d\n", stock_checker(stock));		
		*line = ft_strsub(stock, 0, stock_checker(stock));
	   	stock = ft_strsub(stock, stock_checker(stock) + 1, ft_strlen(stock) - stock_checker(stock));
		return 1;
	}
	return (0);
}
