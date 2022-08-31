/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:26:26 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/31 18:50:05 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char *ft_strdup(char *src);

int	main(int argc, char const *argv[])
{
	int	nb;
	char buf[50] = "Test buffer";
	char *dup; 

	nb = 2;
	if (argc > 1)
		strcpy(buf, argv[1]);
	printf("%s\n", buf);
	dup = ft_strdup(buf);
	printf("%s\n", dup);
	if (dup && dup != buf)
		printf("El string es uno nuevo, con direccion %p\n", dup); 
	else
		printf("El string es, el mismo con direccion %p\n", buf); 
	if (dup)
		free (dup);
	return (0);
}
