/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:58:36 by damartin          #+#    #+#             */
/*   Updated: 2022/05/04 14:58:38 by damartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n);
int		total_digits(int n);

int	printnbr(int nb)
{
	int		total;
	char	*str;

	str = ft_itoa(nb);
	total = printstr(str);
	free(str);
	return (total);
}

int	total_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		digits++;
	if (n < 0)
		digits++;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
