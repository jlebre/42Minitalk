/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:33:40 by jlebre            #+#    #+#             */
/*   Updated: 2022/06/02 03:00:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;
	int	bit;

	if (argc != 3)
		return (ft_red("Arguments are not valid!"));
	if (argv[1] && ft_strlen(argv[1]) == 5)
		pid = ft_atoi(argv[1]);
	else
		return (ft_red("PID is not valid!"));
	while (argv[2] && *argv[2])
	{
		bit = 0;
		while (bit < 8)
		{
			if (*argv[2] & (128 >> bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
			bit++;
		}
		argv[2]++;
	}
	return (0);
}

/*
MAIN
	The main function takes argc and argv as parameters!
	argv[0] will be the compiled program
	argv[1] will be the PID
	argv[2] will be the text to be emitted to the server
	35	If argc != 3 then the arguments are invalid
	39	Check if PID is valid (if it's all num)
	40	The PID is passed as char, we need to convert it to int using atoi
	42	If the PID is not valid - ERR
	(We are gonna send character per character so:)
	43	While argv[2] && *argv[2] - send character
	46	Increment 1
	48	Return 0
*/

/*
FT_SEND
	This function takes the pid and a character as parameters
	Each byte is composed by 8 bits
	We have to check bit per bit
	
	Ex.:
		char = "5" - 00000101
		byte	   - 00000000
		
		Vai confirmar caracter a caracter se é 0 ou 1 e manda sinal
		If 1 - SIGUSR2
		If 0 - SIGUSR1
		
		1:
		char = "5" - 00000101
		byte	   - 0
		SIGUSR1
		
		2:
		char = "5" - 00000101
		byte	   - 00
		SIGUSR1

		3:
		char = "5" - 00000101
		byte	   - 000
		SIGUSR1

		4:
		char = "5" - 00000101
		byte	   - 0000
		SIGUSR1

		5:
		char = "5" - 00000101
		byte	   - 00000
		SIGUSR1

		6:
		char = "5" - 00000101
		byte	   - 000001
		SIGUSR2

		7:
		char = "5" - 00000101
		byte	   - 0000010
		SIGUSR1

		8:
		char = "5" - 00000101
		byte	   - 00000101
		SIGUSR2

		Espera 0.25 seg e passa para o próximo caracter
*/