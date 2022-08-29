/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:35:50 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/26 13:49:46 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

unsigned int ft_strlen(char *str)
{
    unsigned int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

unsigned int	ft_strcpy_ret_size(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (i);
}

int ft_measure_total_length(int size, char **strs, int sep_len)
{
    unsigned int total_length;
    unsigned int i;
    unsigned int len;

    i = 0;
    total_length = 0;
    while (i < size)
    {
        len = 0;
        if (strs[i])
            len = ft_strlen(strs[i]);
        total_length += len;
        if (i < size - 1)
            total_length += sep_len;
        i++;
    }
    return (total_length);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    unsigned int i;
    unsigned int len;
    unsigned int total_length;
    char *dest;
    char *next;

    total_length = ft_measure_total_length(size, strs, ft_strlen(sep));
    dest = (char *)malloc(total_length + 1);
    i = 0;
    next = dest;
    while (i < size)
    {
        if (strs[i])
            next += ft_strcpy_ret_size(next, strs[i]);
        if (i < size - 1)
            next += ft_strcpy_ret_size(next, sep);
        i++;
    }
    return (dest);
}