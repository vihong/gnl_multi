/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:00:03 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/23 19:31:54 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 


int		main()
{
	int		fd = 0;
	char*	line = NULL;

	fd = open("file0", O_RDONLY);
	printf("1er appel de GNL\n");
	get_next_line(fd, &line);
	printf("\n---> GNL renvoie: %s\n", line);	


	
	printf("\n2e appel de GNL\n");
	get_next_line(fd, &line);
	printf("\n---> GNL renvoie: %s\n", line);

	printf("\n3e appel de GNL\n");
	get_next_line(fd, &line);
	printf("\n---> GNL renvoie: %s\n", line);

	printf("\n4e appel de GNL\n");
	get_next_line(fd, &line);
	printf("\n---> GNL renvoie: %s\n", line);

	printf("\n5e appel de GNL\n");
	get_next_line(fd, &line);
	printf("\n---> GNL renvoie: %s\n", line);
	return (0);
}
