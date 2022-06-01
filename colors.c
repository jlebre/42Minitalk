/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:24:00 by jlebre            #+#    #+#             */
/*   Updated: 2022/06/01 17:09:54 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_red(char *str)
{
	ft_printf("\033[0;31m%s\033[0m", str);
}

void	ft_green(char *str)
{
	ft_printf("\033[0;32m%s\033[0m", str);
}

void	ft_yellow(char *str)
{
	ft_printf("\033[0;33m%s\033[0m", str);
}
