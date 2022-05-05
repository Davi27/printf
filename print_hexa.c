/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:40:16 by damartin          #+#    #+#             */
/*   Updated: 2022/05/04 17:40:18 by damartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	recursive_hexa(int nb, const char form);

int	print_hexa(unsigned int nb, const char form)
{
	int				size;
	unsigned int	n;

	n = nb;
	size = 0;
	while (n != 0)
	{
		size++;
		n /= 16;
	}
	if (nb == 0)
		return (write(1, "0", 1));
	else
		recursive_hexa(nb, form);
	return (size);
}

void	recursive_hexa(int nb, const char form)
{
	if (nb >= 16)
	{
		recursive_hexa((nb / 16), form);
		recursive_hexa((nb % 16), form);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (form == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (form == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}
