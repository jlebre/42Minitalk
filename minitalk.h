/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:34:59 by jlebre            #+#    #+#             */
/*   Updated: 2022/06/02 18:29:38 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdarg.h>

int		ft_printf(const char *c, ...);
int		ft_strchr(const char *s, int c);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int k, int fd);
int		ft_putnbr_base_fd(unsigned int n, char *base, int k, int fd);
int		ft_putnbr_p_fd(unsigned long n, char *base, int k, int fd);
int		ft_putpointer_fd(unsigned long ptr, int fd);
int		ft_unsigned(unsigned int nb, int fd);
int		ft_red(char *str);
int		ft_green(char *str);
int		ft_yellow(char *str);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		success(void);
void	ft_receive(int sig);

#endif