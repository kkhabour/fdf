/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:07:14 by kkhabour          #+#    #+#             */
/*   Updated: 2019/04/19 20:17:53 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	char	**str;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_countwords(s, c) + 1;
	if (!(str = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		if (end > start)
			*str++ = ft_strsub(s, start, end - start);
	}
	*str = 0;
	return (str - (len - 1));
}
