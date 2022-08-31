/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:32:39 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/31 20:29:13 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

unsigned int	ft_strlen(char *str);
int	ft_is_this_base(char c, char *base, int *digit_value, unsigned int base_n);
int	ft_take_signs(char **p);
char	ft_get_last_digit(long int *n, int base);
int	ft_atoi_m(char *str, char *base, unsigned int base_n);

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	base_n;
	unsigned int	i;
	unsigned int	j;

	base_n = ft_get_base_nb(base);
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
	char		c;

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
		c = base_code[(unsigned int)store[i]];
		write(1, &c, 1); // write to buf instead to cosole
		i--;
	}
	return (buf)
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
		write(1, "-", 1); //write to buf instead of console
	}
	return (ft_putposnbr (aux, base_code, base, buf));
}

char	*ft_putnbr_base(int nbr, char *base, char *buf)
{
	unsigned int	base_n;
	unsigned int	i;
	unsigned int	j;

	base_n = ft_strlen(base);
	if (base_n < 2)
		return ;
	i = 0;
	while (i < base_n)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ')
			return ;
		j = i + 1;
		while (j < base_n)
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
		i++;
	}
	return (ft_putnbr_ext((long int) nbr, base, base_n), buf);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		aux;
	char	*buf;

	aux = ft_atoi_base(char *nbr, base_from);
	ft_putnbr_base(aux, base_to, buf);
	return (buf);
}
