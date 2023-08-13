/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risufaj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:44:57 by risufaj           #+#    #+#             */
/*   Updated: 2023/08/13 15:38:37 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/* from `board` module */
void	get_row(int **board, int width, int row_index, int *return_buffer);
void	get_col(int **board, int height, int col_index, int *return_buffer);
/* end of `board` module declarations */

bool	is_valid_row_left(int **board, int width, int row_idx,
			int expected_sight);
bool	is_valid_row_right(int **board, int width, int row_idx,
			int expected_sight);
bool	is_valid_col_up(int **board, int height, int col_idx,
			int expected_sight);
bool	is_valid_col_down(int **board, int height, int col_idx,
			int expected_sight);

/*
 * the expected sights for the cols up are in the indices 0 1 2 3
 * the expected sights for the cols down are in the indices 4 5 6 7
 * the expected sights for the row left are in the indices 8 9 10 11
 * the expected sights for the row right are in the indices 12 13 14 15
 */
bool	is_correct(int **board, int width, int height, int *subject)
{
	int	index;

	index = 0;
	while (index < 4)
	{
		if (!is_valid_col_up(board, height, index, subject[index])
			|| !is_valid_col_down(board, height, index, subject[4 + index])
			|| !is_valid_row_left(board, width, index, subject[8 + index])
			|| !is_valid_row_right(board, width, index, subject[12 + index]))
			return (false);
	}
	return (true);
}

bool	is_valid_row_left(int **board, int width, int row_idx,
		int expected_sight)
{
	int	row_buffer[4];
	int	current_highest;
	int	sight;
	int	index;

	get_row(board, width, row_idx, row_buffer);
	index = 0;
	current_highest = 0;
	sight = 0;
	while (index < width)
	{
		if (row_buffer[index] > current_highest)
		{
			current_highest = row_buffer[index];
			sight++;
		}
		index++;
	}
	return (sight == expected_sight);
}

bool	is_valid_row_right(int **board, int width, int row_idx,
		int expected_sight)
{
	int	row_buffer[4];
	int	current_highest;
	int	sight;
	int	index;

	get_row(board, width, row_idx, row_buffer);
	index = width - 1;
	current_highest = 0;
	sight = 0;
	while (index >= 0)
	{
		if (row_buffer[index] > current_highest)
		{
			current_highest = row_buffer[index];
			sight++;
		}
		index--;
	}
	return (sight == expected_sight);
}

bool	is_valid_col_up(int **board, int height, int col_idx,
		int expected_sight)
{
	int	col_buffer[4];
	int	current_highest;
	int	sight;
	int	index;

	get_col(board, height, col_idx, col_buffer);
	index = 0;
	current_highest = 0;
	sight = 0;
	while (index < height)
	{
		if (col_buffer[index] > current_highest)
		{
			current_highest = col_buffer[index];
			sight++;
		}
		index++;
	}
	return (sight == expected_sight);
}

bool	is_valid_col_down(int **board, int height, int col_idx,
		int expected_sight)
{
	int	col_buffer[4];
	int	current_highest;
	int	sight;
	int	index;

	get_col(board, height, col_idx, col_buffer);
	index = height - 1;
	current_highest = 0;
	sight = 0;
	while (index >= 0)
	{
		if (col_buffer[index] > current_highest)
		{
			current_highest = col_buffer[index];
			sight++;
		}
		index--;
	}
	return (sight == expected_sight);
}
