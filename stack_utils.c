/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:50:20 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/14 21:33:20 by gpires-c         ###   ########.fr       */
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
