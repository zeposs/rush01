/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_clues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:19:39 by mkrishan          #+#    #+#             */
/*   Updated: 2026/07/25 19:33:52 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	valid_clues(int row, int col, int arr[SIZE],
		int clues[SIZE * SIZE], int grid[SIZE][SIZE])
{
	/* Row just completed */
	if (col == SIZE - 1)
	{
		rows_from_grid(row, TRUE, arr, grid);
		if (check_visible(arr) != clues[8 + row])
			return (0);

		rows_from_grid(row, FALSE, arr, grid);
		if (check_visible(arr) != clues[12 + row])
			return (0);
	}

	/* Column just completed */
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