/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:58:10 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/23 19:43:55 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 20


int		ft_strlen_bslash(char* s)
{
	int i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

void	split_buf(char* buf, char** for_now, char** for_later)
{
	int len = ft_strlen_bslash(buf);

	*for_now = ft_strsub(buf, 0, len);
	*for_later = ft_strsub(buf, len + 1, BUFF_SIZE - len);
}



int		get_next_line(const int fd, char** line)
{
	char			buf[BUFF_SIZE + 1];
	static	char*	for_now = NULL;
	static	char*	for_later = NULL;
	static	char*	from_before = "";
	static	char*	res = NULL;
	int				ret = 0;

		
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (ret == 0)
	{
		*line = from_before;
		return 0;	
	}
	split_buf(buf, &for_now, &for_later);
	printf("0) %s\n", buf);	
	printf("1) %s\n", from_before);	
	printf("2) %s\n", for_now);	
	printf("3) %s\n", for_later);	

	res = ft_strjoin(from_before, for_now);
	printf("res: %s\n", res);
	from_before = for_later;
	for_later = NULL;
	*line = res;
	return (0);
}






























/*
int get_next_line(const int fd, char** line)
{
	static char		buf[BUFF_SIZE + 1];
	char*			str1;
	char*			str2;
	char*			str_test = "chat";
	static char*	tmp = "";
	int				ret = 0;

	ret = read(fd, buf, BUFF_SIZE);
	printf("BUF A LU:\n\"%s\"\n\n", buf);
	buf[ret] = '\0';
	str1 =  ft_strsub(buf, 0, ft_strlen_bslash(buf));
	printf("str1: %s\n", str1);
	tmp = ft_strchr(buf, '\n');
	printf("tmp: %s\n", tmp);
	*line = str1;
	return (0);
}
*/
