/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 23:08:48 by kkhabour          #+#    #+#             */
/*   Updated: 2019/04/20 22:07:33 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_del(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *node;

	if (!lst || !f)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	node = new;
	while ((lst = lst->next))
	{
		if (!(new->next = f(lst)))
		{
			ft_lstdel(&node, ft_del);
			return (NULL);
		}
		new = new->next;
	}
	return (node);
}
