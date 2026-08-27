/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 22:47:08 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/19 20:58:59 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*pop_first(t_stack **top)
{
	t_stack	*node;

	if (!top || !*top)
		return (NULL);
	node = *top;
	if (!(*top)->next)
	{
		(*top) = NULL;
		return (node);
	}
	(*top)->next->previous = NULL;
	*top = (*top)->next;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

// void	rotate(t_stack	**st)
// {
// 	t_stack	*first;
// 	t_stack	*second;
// 	t_stack	*last;

// 	if (!st || !*st || !(*st)->next)
// 		return ;
// 	first = *st;
// 	second = (*st)->next;
// 	last = *st;
// 	while (last->next)
// 		last = last->next;
// 	(*st) = second;
// 	last->next = first;
// 	first->previous = last;
// 	first->next = NULL;
// }

// void	reverse_rotate(t_stack **st)
// {
// 	t_stack	*first;
// 	t_stack	*last;
// 	t_stack	*penult;

// 	if (!st || !*st || !(*st)->next)
// 		return ;
// 	first = *st;
// 	last = *st;
// 	while (last->next)
// 		last = last->next;
// 	penult = last->previous;
// 	last->next = first;
// 	last->previous = NULL;
// 	first->previous = last;
// 	penult->next = NULL;
// 	*st = last;
// }

// void	swap_top(t_stack **st)
// {
// 	int	content;

// 	if (!st || !*st || !(*st)->next)
// 		return ;
// 	content = (*st)->content;
// 	(*st)->content = (*st)->next->content;
// 	(*st)->next->content = content;
// }


void	rotate(t_stack	**stk, t_stack **stk_tail)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!stk || !*stk || !(*stk)->next)
		return ;
	first = *stk;
	second = (*stk)->next;
	last = *stk_tail;
	second->previous = NULL; //faltava isso na anterior de toda forma (as vezes pode dar erro quando procuramos a primeira por falta de previous)
	(*stk) = second;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	(*stk_tail) = first;
}
