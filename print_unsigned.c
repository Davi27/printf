/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:13:35 by damartin          #+#    #+#             */
/*   Updated: 2022/05/04 17:13:39 by damartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_itoa(unsigned int nb, int size);

int	print_unsigned(unsigned int nb)
{
	int				size;
	unsigned int	n;
	char			*nbstr;

	size = 0;
	n = nb;
	if (nb == 0)
		size += write(1, "0", 1);
	else
	{
		while (n != 0)
		{
			size++;
			n /= 10;
		}
		nbstr = unsigned_itoa(nb, size);
		size += printstr(nbstr);
		free(nbstr);
	}
	return (size);
}

char	*unsigned_itoa(unsigned int nb, int size)
{
	char	*nbstr;

	nbstr = (char *)malloc(sizeof(char) * (size + 1));
	if (!nbstr)
		return (0);
	nbstr[size] = '\0';
	while (nb != 0)
	{
		nbstr[size - 1] = nb % 10 + 48;
		nb /= 10;
		size--;
	}
	return (nbstr);
}
