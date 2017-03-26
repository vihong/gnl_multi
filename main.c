/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:00:03 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/26 19:48:29 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 


int		main()
{
	int		fd = 0;
	char*	line = NULL;
	int		cnt = 1000;

	fd = open("file1", O_RDONLY);

	while (cnt > 0)
	{
		if (get_next_line(fd, &line) == 1)
			printf("%s\n", line);
		cnt--;
	}
/*	fd = open("file0", O_RDONLY);
	printf("1er appel de GNL\n");
	get_next_line(fd, &line);
	printf("%s", line);	



	printf("\n2e appel de GNL\n");
	get_next_line(fd, &line);
	printf("%s", line);

	printf("\n3e appel de GNL\n");
	get_next_line(fd, &line);
	printf("%s", line);	

	printf("\n4e appel de GNL\n");
	get_next_line(fd, &line);
	printf("%s", line);	

	printf("\n5e appel de GNL\n");
	get_next_line(fd, &line);
	printf("%s", line);	*/
	return (0);
}
