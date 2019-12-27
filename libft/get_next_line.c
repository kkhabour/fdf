/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:23:53 by kkhabour          #+#    #+#             */
/*   Updated: 2019/05/09 22:19:27 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_linkedlist		*current_node(int const fd, t_linkedlist **root)
{
	t_linkedlist *node;

	node = *root;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	if (!(node = (t_linkedlist *)malloc(sizeof(t_linkedlist))))
		return (NULL);
	node->fd = fd;
	if (!(node->content = ft_strnew(0)))
		return (NULL);
	node->next = *root;
	*root = node;
	return (node);
}

void				del_node(t_linkedlist **root, t_linkedlist *node)
{
	t_linkedlist *temp;

	temp = *root;
	if (*root == node)
	{
		*root = node->next;
		if (node->content)
			free(node->content);
		free(node);
		return ;
	}
	while (temp->next)
	{
		if (temp->next != node)
		{
			temp = temp->next;
			continue ;
		}
		temp->next = node->next;
		if (node->content)
			free(node->content);
		free(node);
		break ;
	}
}

int					fill_content(char **content, char **line, char *snap)
{
	char	*temp;

	temp = *content;
	if (!(*content = ft_strdup((snap ? snap + 1 : ""))))
	{
		ft_strdel(&temp);
		ft_strdel(line);
		return (-1);
	}
	ft_strdel(&temp);
	return (1);
}

int					read_line(int const fd, t_linkedlist *node, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	char	*snap;
	int		rd;

	while (!(snap = ft_strchr(node->content, '\n')) &&
			(rd = read(fd, buff, BUFF_SIZE)))
	{
		buff[rd] = '\0';
		temp = node->content;
		if (!(node->content = ft_strjoin(node->content, buff)))
		{
			ft_strdel(&temp);
			return (-1);
		}
		ft_strdel(&temp);
	}
	if (rd < BUFF_SIZE && *(node->content) == '\0')
		return (0);
	if (snap)
		*snap = '\0';
	if (!(*line = ft_strdup(node->content)))
		return (-1);
	return (fill_content(&(node->content), line, snap));
}

int					get_next_line(int const fd, char **line)
{
	static t_linkedlist	*root;
	t_linkedlist		*node;
	char				c[1];
	int					ret;

	if (fd < 0 || !line || read(fd, c, 0) < 0)
		return (-1);
	if (!(node = current_node(fd, &root)))
		return (-1);
	ret = read_line(fd, node, line);
	if (ret <= 0)
		del_node(&root, node);
	return (ret);
}
