/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:19:43 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/14 18:21:50 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
    int ret;

    ret = (c == ' ' || c == '\n' || c == '\t');
    ret = ret || (c == '\v' || c == '\f' || c == '\r');

    return (ret);
}

int ft_is_this_base(char c, char *base, int *digit_value, unsigned int base_n)
{
    int             ret;
    unsigned int    i;
    int             found;

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

char	ft_get_last_digit(long int *n, int base)
{
	char	ls;

	ls = *n % base;
	*n = *n / base;
	return (ls);
}

void	ft_putposnbr(long int nb, char *base_code, int base)
{
	int			i;
	char		store[11];
	long int	restant_digits;
	int			s;
    char    	c;

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
        c = base_code[store[i]];
        write(1, &c, 1);
		i--;
	}
}

void	ft_putnbr(long int nb, char *base_code, int base)
{
	char		neg;
	long int	aux;

	neg = (nb < 0);
	aux = nb;
	if (neg)
	{
		aux = -aux;
        write(1, "-", 1);
	}
	ft_putposnbr (aux, base_code, base);
}

int ft_get_base_n(char *base)
{
    int     		base_n;
    unsigned int    i;

    while (base[base_n])
        base_n++;
    if (base_n<2)
        return (0);
    return (base_n);
}

void ft_putnbr_base(int nbr, char *base)
{
    int     		base_n;
    unsigned int    i;
    unsigned int    j;

    base_n = ft_get_base_n(base);
    while (base[base_n])
        base_n++;
    if (base_n<2)
        return;
    i = 0;
    while (i < base_n)
    {
        if (base[i]=='+' || base[i]=='-' || ft_isspace(base[i]))
            return;
        j = i + 1;
        while (j < base_n)
        {
            if (base[i] == base[j])
                return;
            j++;
        }
        i++;
    }
    ft_putnbr((long int) nbr, base, base_n)
}

