/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risufaj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:31:35 by risufaj           #+#    #+#             */
/*   Updated: 2023/08/13 16:32:37 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/* from `board` module */
void	get_row(int **board, int width, int row_index, int *return_buffer);
void	get_col(int **board, int height, int col_index, int *return_buffer);
/* end of `board` module declarations */

bool	row_contains_int(int **board, int row_index, int nbr_to_search,
		int width)
{
	int	i;
	int	row_buffer[4];

	get_row(board, width, row_index, row_buffer);
	i = 0;
	while (i < width)
	{
		if (row_buffer[i] == nbr_to_search && (nbr_to_search > 0
				&& nbr_to_search < 5))
			return (true);
		i++;
	}
	return (false);
}

bool	column_contains_int(int **board, int col_index, int nbr_to_search,
		int height)
{
	int	i;
	int	col_buffer[4];

	get_col(board, height, col_index, col_buffer);
	i = 0;
	while (i < height)
	{
		if (col_buffer[i] == nbr_to_search && (nbr_to_search > 0
				&& nbr_to_search < 5))
			return (true);
		i++;
	}
	return (false);
}

bool	row_is_valid(int **board, int row_index, int width)
{
	return (row_contains_int(board, row_index, 1, width)
		&& row_contains_int(board, row_index, 2, width)
		&& row_contains_int(board, row_index, 3, width)
		&& row_contains_int(board, row_index, 4, width));
}

bool	col_is_valid(int **board, int col_index, int height)
{
	return (column_contains_int(board, col_index, 1, height)
		&& column_contains_int(board, col_index, 2, height)
		&& column_contains_int(board, col_index, 3, height)
		&& column_contains_int(board, col_index, 4, height));
}

bool	board_is_valid(int **board, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (!col_is_valid(board, i, height))
			return (false);
	}
	i = 0;
	while (i < height)
	{
		if (!row_is_valid(board, i, width))
			return (false);
	}
	return (true);
}
