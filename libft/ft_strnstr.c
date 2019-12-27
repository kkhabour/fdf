/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:49:17 by kkhabour          #+#    #+#             */
/*   Updated: 2019/04/19 00:21:56 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t needle_len;

	needle_len = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (len && *haystack)
	{
		if (len < needle_len)
			return (NULL);
		if (ft_strncmp(haystack++, needle, needle_len) == 0)
			return ((char *)haystack - 1);
		len--;
	}
	return (NULL);
}
