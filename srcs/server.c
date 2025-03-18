/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:36:02 by jlebre            #+#    #+#             */
/*   Updated: 2022/06/02 18:28:28 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receive(int sig)
{
	static char	alpha;
	static int	bit;

	if (sig == SIGUSR1)
		alpha |= (128 >> bit);
	bit++;
	if (bit == 8)
	{
		write(1, &alpha, 1);
		alpha = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, ft_receive);
	signal(SIGUSR2, ft_receive);
	while (1)
	{
		pause();
	}
}

//SIGUSR1 - 1
//SIGUSR2 - 0

/*
	1 byte = 00000000
	alpha = comparacao de alpha com 128 em bit (10000000)

	00000000
	10000000
	
	Compara e depois faz >> do 1
	Se for = retorna SIGUSR1
	Se for != retorna SIGUSR2
	
	00000000
	01000000

	00000000
	00100000
*/
