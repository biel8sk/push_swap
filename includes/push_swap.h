/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daneves <daneves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:09:57 by daneves           #+#    #+#             */
/*   Updated: 2026/08/26 02:54:18 by daneves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft.h"

typedef struct s_stack {
	int				content;
	int				pos;
	int				rank;
	int				chunk;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef enum e_flag {
	NONE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
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
	t_flag		selector;
	t_flag		method;
	int			bench;
	double		disorder;
	t_ops_count	operations_count;
	size_t		len;
	int			len_a;
	int			len_b;
	int			num_chunks;
	int			chunk_size;
}	t_program;

typedef struct s_move
{
	t_stack	*node;
	int		cost;
	int		rot_a;
	int		rot_b;
	int		dir_a;
	int		dir_b;
}	t_move;

t_stack	*ft_new_node(int content);
void	ft_push_node(t_stack **lst, t_stack *new);
void	swap_top(t_stack **st);
void	rotate(t_stack	**st);
t_stack	*pop_first(t_stack **top);
void	reverse_rotate(t_stack **st);
void	stack_clear(t_stack **st);
int		stack_contains(int element, t_stack *st);
double	compute_disorder(t_stack *stack_a);
void	print_st(t_stack *stk, char stack);

int		ft_max(int a, int b);
void	assign_labels(t_stack *stk, int chunk_size);
//void	preprocess(t_program *p);
int		set_pos(t_stack *stk);
int		pos_of_min(t_stack *stk);
int		rotate_cost(int pos, int len, int *dir);
int		find_insert_pos(t_stack *stk, int rank, int len_stk);
void	move_cost_ba(t_program *p, t_stack *node, t_move *m);
t_move	best_move_ba(t_program *p);
void	execute_move_ba(t_program *p, t_move *m);

int		ps_flags(int argc, char **argv, t_program *p);
t_flag	flag_from_str(char *arg);
int		ps_atoi(const char *str, int *out);

int		ft_sqrt(int n);
int		ps_error(void);
void	free_program(t_program *p);
void	assign_ranks(t_stack *stk);
int		stk_is_sorted(t_stack *stk);
void	print_rank(t_stack *stk);
t_flag	resolve_strategy(t_flag sel, double disorder);

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
void	sort_medium(t_program *p);
void	sort_complex(t_program *p);

#endif
