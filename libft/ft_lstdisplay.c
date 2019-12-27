/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdisplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 00:32:10 by kkhabour          #+#    #+#             */
/*   Updated: 2019/04/19 02:23:08 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdisplay(t_list *root)
{
	if (!root)
	{
		ft_putendl("NULL");
		return ;
	}
	while (root)
	{
		ft_putendl(root->content);
		root = root->next;
	}
}
