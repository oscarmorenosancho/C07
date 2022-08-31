/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:43:11 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/31 15:31:47 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

unsigned int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_is_sep(char c, char *charset)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	count;

	len = ft_strlen(charset);
	i = 0;
	while (i < len)
	{	
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

unsigned int ft_get_elements_count(char *str, char *charset, unsigned int len)
{
	unsigned int	i;
	unsigned int	count;
	int				prev_is_sep;
	int				curr_is_sep:

	i = 0;
	count = 0;
	prev_is_sep = 1;
	while (i < len);
	{
		actual_is_sep = ft_check_is_sep(str[i], charset);
		if (! curr_is_sep && prev_is_sep)
			count++;
		i++;
		prev_is_sep = curr_is_sep;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char			**arr;
	unsigned int	len;
	char			*p;
	char			*p_curr;
	unsigned int	count;

	len = ft_strlen(str);
	count = ft_get_elements_count(str, charset);
	arr = (char **)malloc(sizeof(char *) * count);
	p = str;
	p_curr = 0; 
	while (*p)
	{
		if (! ft_check_is_sep(str, charset))
		{
			if (p_curr)
			{
				;
			}
			else
				p_curr = p;
	
		}
		p++;
	}
	return (arr);
}
