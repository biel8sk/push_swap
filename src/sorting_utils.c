/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 19:03:04 by daneves           #+#    #+#             */
/*   Updated: 2026/08/30 19:03:04 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

// t_stack	*find_target_rank(t_stack **stk, int rank)
// {
// 	t_stck
// }