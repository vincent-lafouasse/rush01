/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <vlafouas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:02:28 by vlafouas          #+#    #+#             */
/*   Updated: 2023/08/13 14:43:13 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_int_matrix(int **matrix, int height, int width);
void	ft_print_int_array(int *array, int size);
void	ft_putstr(const char *str);
void	ft_putchar(char c);

void	ft_print_int_matrix(int **matrix, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		ft_print_int_array(matrix[i], width);
		i++;
	}
}

void	ft_print_int_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar(array[i] + '0');
		if (i != size - 1)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	ft_putstr(const char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
