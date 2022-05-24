/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:33:40 by jlebre            #+#    #+#             */
/*   Updated: 2022/05/24 17:30:11 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(25);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 3)
		return (ft_printf("Too few arguments!"));
	if (argc > 3)
		return (ft_printf("Too many arguments!"));
	if (ft_isalnum(argv[1]))
		pid = ft_atoi(argv[1]);
	else
		return (ft_printf("PID is not valid!"));
	while (argv[2] && *argv[2])
	{
		ft_send(pid, *argv[2]);
		*argv[2]++;
	}
	return (0);
}

/*
MAIN
	35	If argc != 3 then the arguments are invalid
	39	Check if PID is valid (if it's all num)
	40	The PID is passed as char, we need to convert it to int using atoi
	42	If the PID is not valid - ERR
	43	While argv[2] && *argv[2] - sent character
	46	Increment 1
	48	Return 0
*/

/*
FT_SEND
Each byte is composed by 8 bits
We have to check 
*/