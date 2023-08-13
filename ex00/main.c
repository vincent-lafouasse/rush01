/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <vlafouas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:26:46 by vlafouas          #+#    #+#             */
/*   Updated: 2023/08/13 17:46:07 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/* from `solve` module */
int		**solve(int **board, int width, int height, int *subject);
/* end of `solve` module declarations */

/* from `board` module */
int		**allocate_board(void);
void	free_board(int **board);
/* end of `board` module declarations */

/* from `parse_subject` module */
bool	is_valid_subject(const char *subject);
void	parse_subject(const char *input, int *subject);
/* end of `parse_subject` module declarations */

/* from `print` module */
void	ft_print_int_matrix(int **matrix, int height, int width);
void	ft_putstr(const char *str);
/* end of `print` module declarations */

int		die(const char *str);

int	main(int argc, char **argv)
{
	int	**board;
	int	parsed_subject[16];

	if (argc != 2)
		return (die("invalid argc\n"));
	if (!is_valid_subject(argv[1]))
		return (die("subject is invalid\n"));
	parse_subject(argv[1], parsed_subject);
	board = allocate_board();
	if (board == 0)
		return (die("failed to allocate board\n"));
	board = solve(board, 4, 4, parsed_subject);
	if (board != 0)
		ft_print_int_matrix(board, 4, 4);
	else
		ft_putstr("no solution was found\n");
	free_board(board);
}

int	die(const char *str)
{
	ft_putstr(str);
	return (1);
}
