/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:36:26 by zernest           #+#    #+#             */
/*   Updated: 2026/07/26 13:59:29 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

#include <stdio.h>

int	backtrack(int grid[SIZE][SIZE], int row, int col,
		int arr[SIZE], int clues[SIZE*SIZE])
{
	int	value;
	int	next_row;
	int	next_col;

	if (row == SIZE)
		return (1);
	next_row = row;
	next_col = col + 1;
	if (next_col == SIZE)
	{
		next_col = 0;
		next_row++;
	}
	value = 1;
	while (value <= SIZE)
	{
		if (check_dup(row, col, value, grid))
		{
			grid[row][col] = value;
			if (valid_clues(row, col, arr, clues, grid))
				if (backtrack(grid, next_row, next_col, arr, clues))
					return (1);
			grid[row][col] = 0;
		}
		value++;
	}
	return (0);
}
