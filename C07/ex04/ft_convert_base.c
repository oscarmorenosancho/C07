/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:32:39 by omoreno-          #+#    #+#             */
/*   Updated: 2022/09/02 08:46:33 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int		ft_strlen(char *str);
int		ft_is_this_base(char c, char *base, int *digit_value, int base_n);
int		ft_take_signs(char **p);
char	ft_get_last_digit(long int *n, int base);
int		ft_atoi_m(char *str, char *base, int base_n);

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	base_n;
	unsigned int	i;
	unsigned int	j;

	base_n = ft_strlen(base);
	if (base_n < 2)
	{
		base_n++;
		return (0);
	}
	i = 0;
	while (i < base_n)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ')
			return (0);
		j = i + 1;
		while (j < base_n)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (ft_atoi_m(str, base, base_n));
}

char	*ft_putposnbr(long int nb, char *base_code, int base, char *buf)
{
	int			i;
	char		store[100];
	long int	restant_digits;
	int			s;
	int			neg;

	neg = (buf [0] == '-') & 1;
	restant_digits = nb;
	i = 0;
	s = 0;
	while (restant_digits > 0 || i == 0)
	{
		store[i] = ft_get_last_digit(&restant_digits, base);
		if (restant_digits <= 0)
			s = i;
		i++;
	}
	i = s;
	while (i >= 0)
	{
		buf[s - i + neg] = base_code[(int)store[i]];
		i--;
	}
	buf [s + 1 + neg] = 0;
	return (buf);
}

char	*ft_putnbr_ext(long int nb, char *base_code, int base, char *buf)
{
	char		neg;
	long int	aux;

	neg = (nb < 0);
	aux = nb;
	if (neg)
	{
		aux = -aux;
		buf[0] = '-';
		buf[1] = 0;
	}
	return (ft_putposnbr (aux, base_code, base, buf));
}

int	ft_check_base(char *base)
{
	int	base_n;
	int	i;
	int	j;

	base_n = ft_strlen(base);
	if (base_n < 2)
		return (0);
	i = 0;
	while (i < base_n)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ')
			return (0);
		j = i + 1;
		while (j < base_n)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (base_n);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		aux;
	char	*buf;
	char	*ret;
	int		base_n;

	if (! nbr || ! base_from || ! base_to)
		return (0);
	if (! ft_check_base(base_from))
		return (0);
	base_n = ft_check_base(base_to);
	if (! base_n)
		return (0);
	buf = (char *)malloc(34);
	if (! buf)
		return (0);
	buf[0] = 0;
	aux = ft_atoi_base(nbr, base_from);
	ret = ft_putnbr_ext((long int) aux, base_to, base_n, buf);
	if (! ret)
	{
		free (buf);
		return (0);
	}
	else
		return (buf);
}
