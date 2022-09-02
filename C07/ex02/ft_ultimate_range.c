/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:35:50 by omoreno-          #+#    #+#             */
/*   Updated: 2022/09/02 08:12:24 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	*range = 0;
	size = 0;
	if (max > min)
	{
		size = max - min;
		*range = (int *)malloc(size * sizeof(int));
		i = 0;
		if (*range)
		{
			while (i < size)
			{
				*(*range + i) = min + i;
				i++;
			}
		}
		else
			return (-1);
	}
	else
		return (0);
	return (size);
}
