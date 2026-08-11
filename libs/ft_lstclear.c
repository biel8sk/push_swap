/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 20:37:45 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/17 20:34:46 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (!lst || !del || !*lst)
		return ;
	p = *lst;
	while (p->next != NULL)
	{
		*lst = ((t_list *)*lst)->next;
		ft_lstdelone(p, del);
		p = *lst;
	}
	ft_lstdelone(p, del);
	*lst = 0;
}
