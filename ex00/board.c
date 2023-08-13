/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <vlafouas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:39:54 by vlafouas          #+#    #+#             */
/*   Updated: 2023/08/13 17:47:30 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	get_board_from_index(unsigned int board_index, int **return_board,
		int width, int height)
{
	int	index;

	index = 0;
	while (index < width * height)
	{
		return_board[index / width][index % width] = (board_index % 4) + 1;
		board_index /= 4;
		index++;
	}
}

void	get_row(int **board, int width, int row_index, int *return_buffer)
{
	int	i;

	i = 0;
	while (i < width)
	{
		return_buffer[i] = board[row_index][i];
		i++;
	}
}

void	get_col(int **board, int height, int col_index, int *return_buffer)
{
	int	i;

	i = 0;
	while (i < height)
	{
		return_buffer[i] = board[i][col_index];
		i++;
	}
}

int	**allocate_board(void)
{
	int	*row0;
	int	*row1;
	int	*row2;
	int	*row3;
	int	**board;

	row0 = malloc(4 * sizeof(int));
	row1 = malloc(4 * sizeof(int));
	row2 = malloc(4 * sizeof(int));
	row3 = malloc(4 * sizeof(int));
	board = malloc(4 * sizeof(int *));
	if (board == 0)
		return (0);
	board[0] = row0;
	board[1] = row1;
	board[2] = row2;
	board[3] = row3;
	if (row1 == 0 || row2 == 0 || row3 == 0)
		return (0);
	return (board);
}

void	free_board(int **board)
{
	if (board == 0)
		return ;
	if (board[0])
		free(board[0]);
	if (board[1])
		free(board[1]);
	if (board[2])
		free(board[2]);
	if (board[3])
		free(board[3]);
	free(board);
}
