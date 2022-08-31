/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:11:14 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/31 20:29:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_is_this_base(char c, char *base, int *digit_value, unsigned int base_n)
{
	unsigned int	i;
	int				found;

	i = 0;
	found = 0;
	while (i < base_n && ! found)
	{
		if (base[i] == c)
			found = 1;
		else
			i++;
	}
	if (found)
	{
		*digit_value = i;
		return (1);
	}
	*digit_value = 0;
	return (0);
}

int	ft_take_signs(char **p)
{
	int	minus_counter;

	minus_counter = 0;
	while (**p == '+' || **p == '-')
	{
		if (**p == '-')
			minus_counter++;
		(*p)++;
	}
	if (minus_counter % 2)
		return (-1);
	return (1);
}

int	ft_atoi_m(char *str, char *base, unsigned int base_n)
{
	int		ret;
	int		s;
	char	*p;
	int		digit_value;

	p = str;
	ret = 0;
	while (*p && (*p) <= ' ')
		p++;
	s = ft_take_signs(&p);
	while (ft_is_this_base(*p, base, &digit_value, base_n))
	{
		ret *= base_n;
			ret += digit_value;
		p++;
	}
	ret *= s;
	return (ret);
}

char	ft_get_last_digit(long int *n, int base)
{
	char	ls;

	ls = *n % base;
	*n = *n / base;
	return (ls);
}
