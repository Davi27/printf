/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:59:56 by damartin          #+#    #+#             */
/*   Updated: 2022/05/04 16:59:59 by damartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	recursive_ptr(uintptr_t ptr);

int	print_ptr(unsigned long long ptr)
{
	int					size;
	unsigned long long	n;

	n = ptr;
	size = 0;
	size += write(1, "0x", 2);
	if (ptr == 0)
		size += write(1, "0", 1);
	else
	{
		recursive_ptr(ptr);
		while (n != 0)
		{
			size++;
			n /= 16;
		}
	}
	return (size);
}

void	recursive_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		recursive_ptr(ptr / 16);
		recursive_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}
