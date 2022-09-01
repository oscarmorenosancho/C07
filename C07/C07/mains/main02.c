/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:11:10 by omoreno-          #+#    #+#             */
/*   Updated: 2022/09/01 19:47:55 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int ft_ultimate_range(int **range, int min, int max);

int	main(int argc, char const *argv[])
{
	int	min, max, size, i;
	int *arr; 

	min = 1;
	max = 2;
	if (argc > 2)
	{
		min  = atoi(argv[1]);
		max = atoi(argv[2]);
	}
	printf("min: %d max:%d\n", min, max);
	size = ft_ultimate_range(&arr, min, max);
	printf("size %d\n", size);
	i = 0;
	if (size > 0)
	{
		while (i < size)
		{
			printf("%d\n", arr[i]);
			i++;
		}
	}
	if (arr)
		free (arr);
	return (0);
}
