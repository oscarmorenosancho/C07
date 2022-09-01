/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:26:26 by omoreno-          #+#    #+#             */
/*   Updated: 2022/09/01 16:52:23 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char    *ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(int argc, char const *argv[])
{
	char	nbr[32] = "2";
	char	*conv;
	char 	base_from[50] = "0123456789";
	char	base_to[50] = "0123456789";

	if (argc > 3)
	{
		strcpy(nbr, argv[1]);
		strcpy(base_from, argv[2]);
		strcpy(base_to, argv[3]);
	}
	printf("nbr: %s from: %s to: %s\n", nbr, base_from, base_to);
	conv = ft_convert_base(nbr, base_from, base_to);
	printf("converted %s\n", conv);
	if (conv)
		free (conv);
	return (0);
}
