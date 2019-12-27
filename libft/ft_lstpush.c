/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 00:45:26 by kkhabour          #+#    #+#             */
/*   Updated: 2019/04/19 17:24:02 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **root, t_list *new)
{
	t_list *node;

	node = *root;
	if (!(node->next))
	{
		node->next = new;
		return ;
	}
	while (node)
	{
		if (!(node->next))
		{
			node->next = new;
			break ;
		}
		node = node->next;
	}
}
