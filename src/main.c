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

t_flag	extract_flag(char *arg, double disorder)
{
	if (!ft_strncmp(arg, "--simple", 8))
		return (SIMPLE);
	else if (!ft_strncmp(arg, "--medium", 8))
		return (MEDIUM);
	else if (!ft_strncmp(arg, "--complex", 9))
		return (COMPLEX);
	else if (!ft_strncmp(arg, "--adaptative", 11) || ft_isdigit(*arg))
	{
		if (disorder > 0.0 && disorder < 0.2)
			return (SIMPLE);
		else if (disorder >= 0.2 && disorder < 0.5)
			return (MEDIUM);
		return (COMPLEX);
	}
	return (INVALID);
}

/* VERSAO ORIGINAL (comentada pra comparar/reverter facil) --------------
 * Problema: ft_push_node sempre insere na FRENTE, entao o ULTIMO
 * argumento acaba no topo. O subject pede o contrario: "the first
 * argument is the top of the stack".
 * 
------------------------------------------------------------------- */

/* t_stack	*create_stack(char **argv, int argc, size_t *len)
{
	int		i;
	int		element;
	t_stack	*node;
	t_stack	*ptr;

	i = 1;
	ptr = NULL;
	if (argv[i][0] == '-' && argv[i][1] == '-')
		i++;
	while (i < argc)
	{
		element = ft_atoi(argv[i]);
		if ((element == 0 && argv[i][0] != '0') || stack_contains(element, ptr))
			return (stack_clear(&ptr), NULL);
		node = ft_new_node(element);
		if (!ptr)
			ptr = node;
		else
			ft_push_node(&ptr, node);
		i++;
		(*len)++;
	}
	ft_printf("tamanho da stack: %u", *len);
	return (ptr);
} */
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

// t_program	*create_program(t_stack *st, t_flag fl, size_t len)
// {
// 	t_program	*p;
// 	t_ops_count	*ops;

// 	p = malloc(sizeof(t_program));
// 	if (!p)
// 		return (NULL);
// 	ops = malloc(sizeof(t_ops_count));
// 	if (!ops)
// 		return (free(p), NULL);
// 	*ops = (t_ops_count){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// 	p->a = st;
// 	p->b = NULL;
// 	p->operations_count = *ops;
// 	p->fl = fl;
// 	p->len = len;
// 	return (p);
// }

t_program	*create_program(void)
{
	t_program	*p;

	p = malloc(sizeof(t_program));
	if (!p)
		return (NULL);
	ft_bzero(p, sizeof(t_program));
	return (p);
}

// int	main(int argc, char **argv)
// {
// 	t_stack		*stack;
// 	t_flag		flag;
// 	double		disorder;
// 	t_program	*p;
// 	size_t		len;

// 	if (argc < 3)
// 		return (1);
// 	len = 0;
// 	stack = create_stack(argv, argc, &len);
// 	if (!stack)
// 		return (write(2, "Error\n", 6));
// 	disorder = compute_disorder(stack);
// 	flag = extract_flag(argv[1], disorder);
// 	p = create_program(stack, flag, len);
// 	// ft_printf("Stack Criada!!!!\n");
// 	// print_st(p->a, 'a');
// 	//sort_medium(p);
// 	//sort_simple(p);
// 	sort_complex(p);
// 	print_stack(p);
// 	stack_clear(&stack);
// }




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
	return (0);
}
