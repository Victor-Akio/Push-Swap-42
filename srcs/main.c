/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 05:39:26 by vminomiy          #+#    #+#             */
/*   Updated: 2021/06/26 10:34:46 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

/*
** 	Push-Swap is an application that arrange a sequence of numbers
** starting from the lowest number in a crescent way.
**
** 	The main funcion is responsible to start the application, while receiving 
** the name of the application and an argument;
** 	EX: ./push_swap "5 6 4 3 2 1 0"
**
**
** 	The first step is related to the validation of the argument received
** and if the argument is correctly inputed, it will populate the stack 'a'
**  with the list of numbers;
** 	The next step consist in calling the parsing funcion which is responsible
** for knowing the list's size which will serve as base to better parse 
** the algorithm logic.
**
** 	This application will use 2 stacks that can be used to swap its numbers 
** to arrange the list;
** 	Also, it was given some operations that must be used as
** they were described.
** 	Please, find below the operations allowed:
** - sa :swap 'a' - swap the first 2 elements at the top of stack 'a';
** - sb :swap 'b' - swap the first 2 elements at the top of stack 'b';
** - ss :sa and sb at the same time.
** - pa :push 'a' - take the first element at the top of 'b' and
** put it at the top of 'a'.
** - pb :push 'b' - take the first element at the top of 'a' and
** put it at the top of 'b'.
** - ra :rotate 'a' - shift up all elements of stack 'a' by 1.
** - rb :rotate 'b' - shift up all elements of stack 'b' by 1.
** - rr :ra and rb at the same time.
** - rra :reverse rotate 'a' - shift down all elements of stack 'a' by 1.
** - rrb :reverse rotate 'b' - shift down all elements of stack 'b' by 1;
** - rrr :rra and rrb at the same time.
**
**
** 	The result is the sequence of operations executed by the application
** to arrange the list of numbers.
*/

/*
** fill_args is responsible to identify if the argument is a string of 
** number or a sequence of numbers and will populate the stack 'a'
** accordingly the correct parameters;
*/
char	**fill_args(t_var *v, int ac, char **av)
{
	v->fd = 1;
	if (ac == 2)
		v->split = ft_split(av[1], ' ');
	else
		v->split = &av[1];
	return (v->split);
}

/*
** This is the core of the logic, where it check if the list is valid
** Everything in order, it verify the lenght of the list, 
** if lesser than 11 (being a short list) it follows the sorting proccess
** with up to 10 numbers,or it will use the alternative logic to sort
** larger lists (up to 1500 keeping the efficiency).
*/
void	push_swap(t_var *v, int ac, char **av)
{
	t_stk	*stk;

	stk = NULL;
	v->split = fill_args(v, ac, av);
	check_dup(v->split);
	check_numbers(v->split);
	v->a = fill_list(v, v->split, stk);
	if (check_sort(&v->a, list_size(v->a)) == 1)
		ft_exit_ps("ERROR - invalid list of arguments.\n", 0);
	v->len = list_size(v->a);
	free_stk(&stk);
	if (v->len <= 10)
		sort_short(&(v->a), &(v->b), v->len, v);
	else
		sort_bigger(&(v->a), &(v->b), v->len, v);
	if (ac == 2 || (ac ==3 && v->fd != 1))
		ft_free_array(v->split);
	close(v->fd);
}

/*
** In case of invalid argument, this function is responsible
** to deliver a help message;
*/
void	ft_help(void)
{
	ft_putstr_fd("Push_Swap: How to ...\n", 1);
	ft_putstr_fd("To run the program, please use...\n", 1);
	ft_putstr_fd("./push_swap \"Number sequence\"\n", 1);
}

void	ft_exit_ps(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	exit(err);
}

int	main(int ac, char **av)
{
	t_var	*v;

	v = NULL;
	if (ac < 2)
		ft_exit_ps("Wrong number of arguments", 1);
	else
	{
		v = ft_init_var(v);
		if (!ft_strcmp(av[1], "-h"))
			ft_help();
		else
			push_swap(v, ac, av);
		free(v);
		v = NULL;
	}
}
