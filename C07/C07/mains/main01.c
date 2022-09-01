/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:11:10 by omoreno-          #+#    #+#             */
/*   Updated: 2022/09/01 18:53:13 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int *ft_range(int min, int max);

int	main(int argc, char const *argv[])
{
	int	min, max, i, size;
	int *arr; 

	min = 1;
	max = 2;
	if (argc > 2)
	{
		min  = atoi(argv[1]);
		max = atoi(argv[2]);
	}
	size = max - min;
	if (size < 0) return (0);
	arr = ft_range(min, max);
	i = 0;
	while(i<size)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	if (arr)
		free (arr);
	return (0);
}
