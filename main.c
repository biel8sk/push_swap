/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:05:05 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/15 21:01:01 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flag	extract_flag(char *argv)
{
	if (!ft_strncmp(argv, "--simple", 8))
		return (SIMPLE);
	else if (!ft_strncmp(argv, "--medium", 8))
		return (MEDIUM);
	else if (!ft_strncmp(argv, "--complex", 9))
		return (COMPLEX);
	else if (!ft_strncmp(argv, "--adaptative", 11) || ft_isdigit(*argv))
		return (ADAPTATIVE);
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

int	stack_contains(int element, t_stack *st)
{
	while (st)
	{
		if (element == st->content)
			return (1);
		st = st->next;
	}
	return (0);
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
			return (NULL); // liberar a stack aq
		node = ft_new_node(element);
		if (!ptr)
			ptr = node;
		else
			ft_push_node(&ptr, node);
		i++;
	}
	return (ptr);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_flag	flag;
	double	disorder;

	flag = ADAPTATIVE;
	if (argc < 3)
		return (1);
	if (argv[1][0] == '-')
		flag = extract_flag(argv[1]);
	if (flag == INVALID)
		return (write(2, "Error\n", 6));
	stack = create_stack(argv, argc);
	if (!stack)
		return (write(2, "Error\n", 6));
	disorder = compute_disorder(stack);
	ft_printf("stack: ");
	while (stack)
	{
		ft_printf("%d", stack->content);
		stack = stack->next;
	}
	ft_printf("\nflag: %d\n", flag);
}
