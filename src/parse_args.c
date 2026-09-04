/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 04:21:33 by daneves           #+#    #+#             */
/*   Updated: 2026/09/04 04:21:33 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_atoi(const char *str, int *out)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
	{
		n = n * 10 + (*str++ - '0');
		if (n > 2147483648L)
			return (0);
	}
	if (*str || (sign == 1 && n > 2147483647L))
		return (0);
	*out = (int)(n * sign);
	return (1);
}

int	ps_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	free_program(t_program *p)
{
	if (!p)
		return ;
	stack_clear(&p->a);
	stack_clear(&p->b);
	free(p);
}

void	assign_ranks(t_stack *stk)
{
	t_stack	*curr;
	t_stack	*other;
	int		count;

	curr = stk;
	while (curr)
	{
		count = 0;
		other = stk;
		while (other)
		{
			if (other->content < curr->content)
				count++;
			other = other->next;
		}
		curr->rank = count;
		curr = curr->next;
	}
}
