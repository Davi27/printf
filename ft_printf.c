/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:36:39 by damartin          #+#    #+#             */
/*   Updated: 2022/05/04 13:37:04 by damartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(va_list args, char form)
{
	int	size;

	size = 0;
	if (form == 'c')
		size += printchar(va_arg(args, int));
	else if (form == 's')
		size += printstr(va_arg(args, char *));
	else if (form == 'p')
		size += print_ptr(va_arg(args, unsigned long long));
	else if (form == 'd')
		size += printnbr(va_arg(args, int));
	else if (form == 'i')
		size += printnbr(va_arg(args, int));
	else if (form == 'u')
		size += print_unsigned(va_arg(args, unsigned int));
	else if (form == 'x')
		size += print_hexa(va_arg(args, unsigned int), form);
	else if (form == 'X')
		size += print_hexa(va_arg(args, unsigned int), form);
	else if (form == '%')
		size += printchar('%');
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total_size;
	va_list	arg;

	i = 0;
	total_size = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			total_size += format(arg, str[i++]);
		else
			total_size += printchar(str[i]);
		i++;
	}
	va_end(arg);
	return (total_size);
}

int main(void)
{
	char a, b, c;

	a = 'a';
	b = 'v';
	c = 'q';
	ft_printf("Testing chars: %c, %c, %c\n", a, b, c);
	return (0);
}