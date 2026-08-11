/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 20:59:09 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/14 15:13:21 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p;

	p = lst;
	if (!lst || !f)
		return ;
	while (p->next != NULL)
	{
		f(p->content);
		p = p->next;
	}
	f(p->content);
}
