/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:43:53 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/30 16:43:56 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char			*str;
	char			*str1;
	char			*str2;
	unsigned int	len;
	unsigned int	i;

	str1 = (char*)s1;
	str2 = (char*)s2;
	len = ft_strlen(str1) + ft_strlen(str2);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (str);
	i = 0;
	while (i < len)
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = '\0';
	ft_strcat(str, str2);
	free((void*)s1);
	return (str);
}