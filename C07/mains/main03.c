/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:50:44 by omoreno-          #+#    #+#             */
/*   Updated: 2022/09/02 08:51:44 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char *ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char *argv[])
{
	int	size, i;
	char *strs[50] = "";
	char *sep;
	char *joined;

	size = 0;
	joined = 0;
	if (argc > 2)
	{
		sep = argv[1];
		size = argc - 2;
		for (i = 0;i<size;i++)
			strs[i] = argv[i + 2];
		joined = ft_strjoin(size, strs, sep);
		printf("size %d\n", size);
		printf("%s\n", joined);
	}
	if (joined)
		free (joined);
	return (0);
}
