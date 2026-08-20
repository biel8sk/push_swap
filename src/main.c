/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:05:05 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/19 21:05:51 by gpires-c         ###   ########.fr       */
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

double	compute_disorder(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*next;
	double	mistakes;
	double	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	current = stack_a;
	while (current->next)
	{
		next = current->next;
		while (next)
		{
			total_pairs++;
			if (current->content > next->content)
				mistakes++;
			next = next->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}

t_stack	*create_stack(char **argv, int argc)
{
	int		i;
	int		element;
	t_stack	*node;
	t_stack	*ptr;

	i = 1;
	ptr = NULL;
	if (argv[i][0] == '-')
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
	}
	return (ptr);
}

void	print_stack(t_stack *st)
{
	ft_putstr_fd("stack ordenada: ", 1);
	while (st)
	{
		ft_printf("%d -> ", st->content);
		st = st->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_flag	flag;
	double	disorder;

	if (argc < 3)
		return (1);
	stack = create_stack(argv, argc);
	if (!stack)
		return (write(2, "Error\n", 6));
	disorder = compute_disorder(stack);
	flag = extract_flag(argv[1], disorder);
	sort_simple(&stack);
	print_stack(stack);
	stack_clear(&stack);
}
