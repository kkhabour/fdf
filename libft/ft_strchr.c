/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:00:39 by kkhabour          #+#    #+#             */
/*   Updated: 2019/04/10 17:13:26 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s) + 1;
	while (len--)
		if (*s++ == (char)c)
			return ((char *)s - 1);
	return (NULL);
}
