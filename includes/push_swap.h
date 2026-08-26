/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 21:35:32 by gpires-c          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/08/22 03:08:06 by gpires-c         ###   ########.fr       */
=======
/*   Updated: 2026/08/22 02:53:38 by daneves          ###   ########.fr       */
>>>>>>> dani
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft.h"

typedef struct s_stack {
	int				content;
	size_t			idx_start;
	size_t			idx_end;
	size_t			chuck;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef enum e_flag {
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTATIVE,
	INVALID,
}	t_flag;

typedef struct s_ops_count {
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops_count;

typedef struct s_program {
	t_stack		*a;
	t_stack		*b;
	t_flag		fl;
	t_ops_count	operations_count;
	size_t		len;
}	t_program;

t_stack	*ft_new_node(int content);
void	ft_push_node(t_stack **lst, t_stack *new);
void	swap_top(t_stack **st);
void	rotate(t_stack	**st);
t_stack	*pop_first(t_stack **top);
void	reverse_rotate(t_stack **st);
void	stack_clear(t_stack **st);
int		stack_contains(int element, t_stack *st);
double	compute_disorder(t_stack *stack_a);

void	sa(t_program *p);
void	sb(t_program *p);
void	ss(t_program *p);
void	pa(t_program *p);
void	pb(t_program *p);
void	ra(t_program *p);
void	rb(t_program *p);
void	rr(t_program *p);
void	rra(t_program *p);
void	rrb(t_program *p);
void	rrr(t_program *p);

void	sort_simple(t_program *p);

#endif
