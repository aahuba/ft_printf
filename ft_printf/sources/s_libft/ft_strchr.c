/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:55:46 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/24 05:29:33 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	while (++i < (int)ft_strlen(s) + 1)
		if (s[i] == c)
			return ((char *)s + i);
	return (NULL);
}
