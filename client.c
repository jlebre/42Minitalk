/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:33:40 by jlebre            #+#    #+#             */
/*   Updated: 2022/06/08 18:10:54 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;
	int	bit;

	pid = 0;
	if (argc != 3)
		return (ft_red("Arguments are not valid!"));
	if (argv[1])
		pid = ft_atoi(argv[1]);
	if (!pid)
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
			usleep(50);
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
		If argc != 3 then the arguments are invalid
		Check if PID is valid
		The PID is passed as char, we need to convert it to int using atoi
		If the PID is not valid - ERR
		(We are gonna send character per character so:)
		While argv[2] && *argv[2] - send character
			Send char
		Increment 1
		After everything is done, send the success message
		Return 0
*/
