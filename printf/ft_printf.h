/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:16:48 by jlebre            #+#    #+#             */
/*   Updated: 2022/02/24 20:25:01 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *c, ...);
int	ft_strlen(const char *str);
int	ft_strchr(const char *s, int c);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int k, int fd);
int	ft_putnbr_base_fd(unsigned int n, char *base, int k, int fd);
int	ft_putnbr_p_fd(unsigned long n, char *base, int k, int fd);
int	ft_putpointer_fd(unsigned long ptr, int fd);
int	ft_unsigned(unsigned int nb, int fd);

#endif
