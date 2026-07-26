/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:08:18 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/07/26 14:43:46 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_valid_argv(char *argv, int *clues)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (argv[i])
	{
		if (i % 2 == 0)
		{
			if (argv[i] >= '1' && argv[i] <= '4')
			{
				clues[index] = argv[i] - '0';
				index++;
			}
			else
				return (0);
		}
		else if (i % 2 == 1 && argv[i] != ' ')
			return (0);
		i++;
	}
	if (i != 31 || index != 16)
		return (0);
	return (1);
}

void	init_grid(int grid[SIZE][SIZE])
{
	int	row;
	int	col;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	main(int argc, char *argv[])
{
	int	clues[SIZE * SIZE];
	int	grid[SIZE][SIZE];
	int	arr[SIZE];

	init_grid(grid);
	if (argc == 2 && check_valid_argv(argv[1], clues) && backtrack(grid, 0, 0, arr, clues))
		display_grid(grid);
	else
		write(1, "Error", 5);
	return (0);
}
