/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:11:10 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/31 19:17:03 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int *ft_range(int min, int max)

int	main(int argc, char const *argv[])
{
	int	min, max;
	char *arr; 

	min = 1;
	max = 2;
	if (argc > 2)
	{
		min  = atoi(argv[1]);
		max = atoi(argv[2]);
	}
	arr = ft_rangeft_strdup(min, max);
	printf("%s\n", dup);
	if (arr)
		free (arr);
	return (0);
}
