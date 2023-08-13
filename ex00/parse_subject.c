/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subject.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogeneve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:01:19 by rogeneve          #+#    #+#             */
/*   Updated: 2023/08/13 16:29:30 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		ft_strlen(const char *str);

/*
 * once we know the string subject is valid, we need to parse properly into
 * the int array `parsed_subject`.
 *
 * We will be using the fact that digits in the raw_subject are present at
 * the _even_ positions.
 */
void	parse_subject(const char *raw_subject, int *parsed_subject)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		parsed_subject[i] = raw_subject[2 * i] - '0';
		i++;
	}
}

/*
 * Raw input subject should be 16 digits between 1 and 4 separated by spaces
 * hence it should have a length of 31, with digits on even positions and
 * spaces on odd positions
 * 
 * Anything other than that is invalid
 */
bool	is_valid_subject(const char *subject)
{
	int	i;

	if (ft_strlen(subject) != 31)
		return (false);
	i = 0;
	while (subject[i] != '\0')
	{
		if (i % 2 == 1 && subject[i] != ' ')
			return (false);
		i++;
	}
	i = 0;
	while (subject[i] != '\0')
	{
		if (i % 2 == 0 && !((subject[i] >= '1') && (subject[i] <= '4')))
			return (false);
		i++;
	}
	return (true);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*valid_input;
	const char	*invalid_input1;
	const char	*invalid_input2;
	const char	*invalid_input3;
	bool		is_valid;

	// int			parsed_subject[16];
	valid_input = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	invalid_input1 = "4 3 2 1 12 2  4 3 2 1 1 2 2 2";
	invalid_input2 = "4 3 2 1 1 2 2 2 4 3 2 1 1";
	invalid_input3 = "4 3 2 1 1 2 2 2 4 3 2 1 1 5 6 3 2 1 689 w";
	is_valid = is_valid_subject(valid_input);
	if (is_valid)
	{
		printf("ok :) the raw subject is valid\n");
	}
	else
	{
		printf("rip :( the raw subject is not valid\n");
	}
}
*/
