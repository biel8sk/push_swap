/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpires-c <gpires-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:05:05 by gpires-c          #+#    #+#             */
/*   Updated: 2026/08/12 17:43:07 by gpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	extract_flag(char *argv)
{
	if (ft_strncmp(argv, "--simple", 8))
		return ('s');
	else if (ft_strncmp(argv, "--medium", 8))
		return ('m');
	else if (ft_strncmp(argv, "--complex", 9))
		return ('c');
	else if (ft_strncmp(argv, "--adaptative", 11) || ft_isdigit(*argv))
		return ('a');
	return ('i');
}

int	*extract_stack(char **argv, int argc)
{
	int	i;
	int	*stack;

	i = 1;
	if (argv[i][0] == '-')
		i++;
	stack = malloc(argc - i * sizeof(int));
	if (!stack)
		return (NULL);
	ft_printf("elementos na stack: ");
	while (i < argc)
	{
		ft_printf("%s ", argv[i]);
		*stack = ft_atoi(argv[i]);
		stack++;
		i++;
	}
	ft_printf("\n");
	return (stack);
}

int	main(int argc, char **argv)
{
	int		*stack;
	char	flag;

	flag = 'a';
	if (argc < 2)
		return (1);
	if (argv[1][0] == '-')
		flag = extract_flag(argv[1]);
	stack = extract_stack(argv, argc);
}
