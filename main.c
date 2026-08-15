/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:05:05 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/14 21:55:36 by gpires-c         ###   ########.fr       */
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

t_stack	*extract_stack(int *input, size_t len_stack)
{
	t_stack	*new;
	t_stack	*ptr;
	int		element;
	size_t	i;

	i = 0;
	ptr = NULL;
	while (i < len_stack)
	{
		new = ft_new_node(input[i]);
		if (!new)
			return (NULL);
		if (!ptr)
			ptr = new;
		else
			ft_push_node(&ptr, new);
	}
	return (ft_printf("\nnumero de elementos: %d\n", len_stack), ptr);
}

double	compute_disorder(t_stack *stack_a, size_t len_stack)
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

int	main(int argc, char **argv)
{
	t_stack		*stack;
	t_flag		flag;
	double		disorder;
	int			*list;
	size_t		len_stack;

	if (argc < 2)
		return (1);
	stack = create_stack(argv, argc);
	if (!stack)
		return (ft_printf("Error\n"), 1);
	disorder = compute_disorder(stack, len_stack);
}
