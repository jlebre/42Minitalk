/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:33:28 by jlebre            #+#    #+#             */
/*   Updated: 2022/02/24 20:33:28 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (ft_strlen(s));
}

int	ft_putnbr_fd(int n, int k, int fd)
{
	if (n == (-2147483648))
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		k++;
		n = -n;
	}
	k++;
	if (n > 9)
	{
		k = ft_putnbr_fd(n / 10, k, fd);
		n %= 10;
	}
	ft_putchar_fd(n + '0', fd);
	return (k);
}

int	ft_putnbr_base_fd(unsigned int n, char *base, int k, int fd)
{
	k++;
	if (n > 15)
	{
		k = ft_putnbr_base_fd(n / 16, base, k, fd);
		n %= 16;
	}
	ft_putchar_fd(base[n], fd);
	return (k);
}
