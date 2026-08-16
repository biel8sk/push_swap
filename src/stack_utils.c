/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:50:20 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/16 02:04:29 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	ft_push_node(t_stack **lst, t_stack *new)
{
	t_stack	*p;

	p = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = new;
		new->previous = p;
	}
}

void	stack_clear(t_stack **st)
{
	t_stack	*tmp;

	if (!st || !*st)
		return ;
	while (*st)
	{
		tmp = *st;
		*st = (*st)->next;
		free(tmp);
	}
	*st = NULL;
}

int	stack_contains(int element, t_stack *st)
{
	while (st)
	{
		if (element == st->content)
			return (1);
		st = st->next;
	}
	return (0);
}
