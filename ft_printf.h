/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:43:21 by damartin          #+#    #+#             */
/*   Updated: 2022/05/04 13:43:27 by damartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "Libft/libft.h"

int	ft_printf(const char *format, ...);

int	printchar(int c);
int	printstr(char *str);
int	print_ptr(unsigned long long ptr);
int	printnbr(int nb);
int	print_unsigned(unsigned int nb);
int	print_hexa(unsigned int nb, const char form);

#endif
