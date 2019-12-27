/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:09:40 by kkhabour          #+#    #+#             */
/*   Updated: 2019/04/09 22:05:16 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len - 1;
	if (size < dest_len)
		return (size + src_len);
	while (*dest)
		dest++;
	while (++i < size - 1 && *src)
		*dest++ = *src++;
	*dest = 0;
	return (dest_len + src_len);
}
