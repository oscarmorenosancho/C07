/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:35:50 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/26 13:49:46 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int *ft_range(int min, int max)
{
    int *arr;
    unsigned int size;
    unsigned int i;

    if (max > min)
    {
        size = max - min;
        arr = (int *)malloc(size * sizeof int);
        i = min;
        if (arr)
        {
            while (i < max)
            {
                arr[i - min] = i
                i++;
            }
        }
        return (arr);
    }
    return (0);
}