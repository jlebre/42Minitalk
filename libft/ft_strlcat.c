/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:43:14 by jlebre            #+#    #+#             */
/*   Updated: 2021/11/16 17:50:39 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	int		i;
	int		j;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	j = size_dest;
	i = 0;
	if ((size_dest < (size - 1)) && (size > 0))
	{
		while ((src[i] != '\0') && ((size_dest + i) < (size - 1)))
		{
			dest[j] = src[i];
			j++;
			i++;
		}
		dest[j] = 0;
	}
	if (size_dest >= size)
		size_dest = size;
	return (size_dest + size_src);
}
