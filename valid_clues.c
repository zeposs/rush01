/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:19:39 by mkrishan          #+#    #+#             */
/*   Updated: 2026/07/26 14:46:35 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

//checking if the rows/column has duplicates
int	check_dup(int row, int col, int nbr, int grid[SIZE][SIZE])
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] == nbr)
			return (0);
		if (grid[i][col] == nbr)
			return (0);
		i++;
	}
	return (1);
}

//plucking rows out from grid
void	rows_from_grid(int row, int view_point, int arr[SIZE], int grid[SIZE][SIZE])
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (view_point == TRUE)
		{
			arr[i] = grid[row][i];
		}
		else
		{
			arr[i] = grid[row][(SIZE - 1) - i];
		}
		i++;
	}
}

//plucking columns out from grid
void	cols_from_grid(int col, int view_point, int arr[SIZE], int grid[SIZE][SIZE])
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (view_point == TRUE)
		{
			arr[i] = grid[i][col];
		}
		else
		{
			arr[i] = grid[(SIZE - 1) - i][col];
		}
		i++;
	}
}

//checking how many buildings are visible
//not sorting, just checking
int	check_visible(int arr[SIZE])
{
	int	i;
	int	visible;
	int	tallest;

	i = 0;
	visible = 0;
	tallest = 0;
	while (i < SIZE)
	{
		if (arr[i] > tallest)
		{
			tallest = arr[i];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	valid_clues(int row, int col, int arr[SIZE],
		int clues[SIZE*SIZE], int grid[SIZE][SIZE])
{
	if (col == SIZE - 1)
	{
		rows_from_grid(row, TRUE, arr, grid);
		if (check_visible(arr) != clues[8 + row])
			return (0);
		rows_from_grid(row, FALSE, arr, grid);
		if (check_visible(arr) != clues[12 + row])
			return (0);
	}
	if (row == SIZE - 1)
	{
		cols_from_grid(col, TRUE, arr, grid);
		if (check_visible(arr) != clues[col])
			return (0);
		cols_from_grid(col, FALSE, arr, grid);
		if (check_visible(arr) != clues[4 + col])
			return (0);
	}
	return (1);
}
