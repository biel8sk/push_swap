/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:05:05 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/26 02:04:22 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char **argv, int argc, size_t *len)
{
	int		i;
	int		element;
	t_stack	*node;
	t_stack	*stk;
	t_stack	*tail;

	i = 0;
	stk = NULL;
	tail = NULL;
	while (i < argc)
	{
		if (!ps_atoi(argv[i], &element) || stack_contains(element, stk))
			return (stack_clear(&stk), NULL);
		node = ft_new_node(element);
		if (!node)
			return (stack_clear(&stk), NULL);
		if (!stk)
			stk = node;
		else
		{
			tail->next = node;
			node->previous = tail;
		}
		tail = node;
		i++;
		(*len)++;
	}
	return (stk);
}

void	run_sort(t_program *p)
{
	if (stk_is_sorted(p->a))
		return ;
	if (p->method == SIMPLE)
		sort_simple(p);
	else if (p->method == MEDIUM)
		sort_medium(p);
	else
		sort_complex(p);
}

void	print_stack(t_program *p)
{
	t_stack	*curr;

	curr = p->a;
	ft_putstr_fd("stack ordenada: ", 2);
	while (curr)
	{
		ft_printfd(2, "%d -> ", curr->content);
		curr = curr->next;
	}
	ft_putstr_fd("\n", 2);
}

t_program	*create_program(void)
{
	t_program	*p;

	p = malloc(sizeof(t_program));
	if (!p)
		return (NULL);
	ft_bzero(p, sizeof(t_program));
	return (p);
}

int	main(int argc, char **argv)
{
	t_program	*p;
	int			start;

	p = create_program();
	if (!p)
		return (1);
	start = ps_flags(argc, argv, p);
	if (start < 0)
		return (free_program(p), ps_error());
	if (start >= argc)
		return (free_program(p), 0);
	p->a = create_stack(argv + start, argc - start, &p->len);
	if (!p->a)
		return (free_program(p), ps_error());
	assign_ranks(p->a);
	ft_printfd(2, "len=%u sel=%d bench=%d start=%d\n",
		p->len, p->selector, p->bench, start);
	print_st(p->a, 'a');
	print_rank(p->a);
	p->disorder = compute_disorder(p->a);
	p->method = resolve_strategy(p->selector, p->disorder);
	run_sort(p);
	free_program(p);
	return (0);
}
