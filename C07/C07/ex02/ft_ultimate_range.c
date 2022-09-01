/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:35:50 by omoreno-          #+#    #+#             */
/*   Updated: 2022/09/01 19:43:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	arr = 0;
	size = 0;
	if (max > min)
	{
		size = max - min;
		arr = (int *)malloc(size * sizeof(int));
		i = 0;
		if (arr)
		{
			while (i < size)
			{
				arr[i] = min + i;
				i++;
			}
		}
	}
	else
		return (-1);
	*range = arr;
	return (size);
}
