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
#include<stdio.h>

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

int	ft_check_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{	
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

unsigned int ft_get_elements_count(char *str, char *charset)
{
	unsigned int	i;
	unsigned int	count;
	int				prev_is_sep;
	int				curr_is_sep;

	i = 0;
	count = 0;
	prev_is_sep = 1;
	curr_is_sep = 0;
	while (str[i])
	{
		curr_is_sep = ft_check_is_sep(str[i], charset);
		if (! curr_is_sep && prev_is_sep)
			count++;
		i++;
		prev_is_sep = curr_is_sep;
	}
	return (count);
}

char *ft_find_next_word(char *str, char *charset, char **p)
{
	char			*word;
	char			*word_start;
	char			*word_end;
	unsigned int	size;

	word_start = *p;
	word_end = *p;
	while (*word_start && ft_check_is_sep(*word_start, charset))
		word_start++;
	word_end = word_start;
	while (*word_end && ! ft_check_is_sep(*word_end, charset))
	{
		word_end++;
	}
	size = word_end - word_start;
	if (size > 0)
	{
		word = (char *)malloc(size + 1);
		if (word)
			ft_strncpy(word, word_start, size);
	}
	*p = word_end;
	return (word); 
}

char	**ft_split(char *str, char *charset)
{
	char			**arr;
	char			*p;
	unsigned int	count;
	unsigned int	wc;

	count = ft_get_elements_count(str, charset);
	printf("word count %d\n", count);
	if (count > 0)
	{
		arr = (char **)malloc(sizeof(char *) * (count + 1));
		if (arr)
		{
			arr[count] = 0;
			wc = 0;
			p = str;
			while (wc < count)
			{
				arr[wc] = ft_find_next_word(str,charset, &p);
				if (! arr[wc])
					return (arr);
				wc++;
			}
		}
	}
	return (arr);
}
