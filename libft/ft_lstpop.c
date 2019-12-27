/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 01:31:51 by kkhabour          #+#    #+#             */
/*   Updated: 2019/04/19 17:22:39 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

void			ft_lstpop(t_list **root)
{
	t_list *node;

	node = *root;
	if ((*root)->next == NULL)
	{
		ft_lstdelone(root, del);
		return ;
	}
	while (node->next->next)
		node = node->next;
	ft_lstdelone(&node->next, del);
	node->next = NULL;
}
