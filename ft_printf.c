/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 05:38:17 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/21 07:06:25 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_form(va_list args, const char form)
{
	if (form == 'd' || form == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (form == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (form == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (form == '%')
		return (ft_putchar('%'));
	if (form == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	if (form == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	if (form == 'p')
		return (ft_putptr(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%' && form[i + 1])
		{
			count += ft_form(args, form[i + 1]);
			i += 2;
		}
		else
			count += ft_putchar(form[i++]);
	}
	va_end(args);
	return (count);
}
