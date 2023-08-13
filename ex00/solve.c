/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <vlafouas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:43:50 by vlafouas          #+#    #+#             */
/*   Updated: 2023/08/13 17:49:25 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/* from `board` module */
void	get_board_from_index(unsigned int board_index, int **return_board,
			int width, int height);
/* end of `board` module declarations */

/* from `validate_board` module */
bool	board_is_valid(int **board, int width, int height);
/* end of `validate_board` module declarations */

/* from `verify` module */
bool	is_correct(int **board, int width, int height, int *subject);
/* end of `verify` module declarations */

int	**solve(int **board, int width, int height, int *subject)
{
	unsigned int	board_index;

	board_index = 1;
	while (board_index != 0)
	{
		get_board_from_index(board_index, board, width, height);
		if (!board_is_valid(board, width, height))
		{
			board_index++;
			continue ;
		}
		if (is_correct(board, width, height, subject))
			return (board);
		board_index++;
	}
	return (0);
}
