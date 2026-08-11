/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:35:13 by gpires-c          #+#    #+#             */
/*   Updated: 2026/06/12 20:23:58 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *first)
{
	t_list	*p;

	p = first;
	if (!p)
		return (p);
	while (p->next != NULL)
		p = p->next;
	return (p);
}
