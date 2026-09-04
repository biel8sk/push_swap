/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 02:53:43 by daneves           #+#    #+#             */
/*   Updated: 2026/09/04 02:53:43 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flag	flag_from_str(char *arg)
{
	if (!ft_strncmp(arg, "--simple", 9))
		return (SIMPLE);
	if (!ft_strncmp(arg, "--medium", 9))
		return (MEDIUM);
	if (!ft_strncmp(arg, "--complex", 10))
		return (COMPLEX);
	if (!ft_strncmp(arg, "--adaptive", 11))
		return (ADAPTIVE);
	return (INVALID);
}

int	ps_flags(int argc, char **argv, t_program *p)
{
	int		i;
	t_flag	flag;

	i = 1;
	p->bench = 0;
	p->selector = NONE;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
			p->bench = 1;
		else
		{
			flag = flag_from_str(argv[i]);
			if (p->selector != NONE || flag == INVALID)
				return (-1);
			p->selector = flag;
		}
		i++;
	}
	if (p->selector == NONE)
		p->selector = ADAPTIVE;
	return (i);
}
t_flag	resolve_strategy(t_flag sel, double disorder)
{
	if (sel != ADAPTIVE)
		return (sel);
	if (disorder < 0.2)
		return (SIMPLE);
	if (disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}
