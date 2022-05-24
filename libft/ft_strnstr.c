/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:03:40 by jlebre            #+#    #+#             */
/*   Updated: 2021/11/18 17:46:27 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!s2[0])
		return ((char *)s1);
	i = 0;
	while ((s1[i]) && (i < n))
	{
		j = 0;
		while ((s1[i + j]) && (s2[j])
			&& (i + j < n) && (s1[i + j] == s2[j]))
			j++;
		if (!s2[j])
			return ((char *)(s1 + i));
		i++;
	}
	return (0);
}
