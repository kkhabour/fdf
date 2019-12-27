/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:35:29 by kkhabour          #+#    #+#             */
/*   Updated: 2019/04/20 20:08:06 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (src > dest)
		return (ft_memcpy(dest, src, len));
	while (len--)
		*(char *)(dest + len) = *(char *)(src + len);
	return (dest);
}
