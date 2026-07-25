/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_clues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:19:39 by mkrishan          #+#    #+#             */
/*   Updated: 2026/07/25 18:43:28 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	valid_clues(int row, int col, int arr[SIZE], int clues[SIZE * SIZE], int grid[SIZE][SIZE])
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		cols_from_grid(col, TRUE, arr, grid);
		if (clues[i] != 0 && check_visible(arr) != clues[i])
			return (0);
		cols_from_grid(col, FALSE, arr, grid);
		if (clues[i + SIZE] != 0 && check_visible(arr) != clues[i + SIZE])
			return (0);
		rows_from_grid(row, TRUE, arr, grid);
		if (clues[i + (SIZE * 2)] != 0 && check_visible(arr) != clues[i + (SIZE * 2)])
			return (0);
		rows_from_grid(row, FALSE, arr, grid);
		if (clues[i + (SIZE * 3)] != 0 && check_visible(arr) != clues[i + (SIZE * 3)])
			return (0);
		i++;
	}
	return (1);
}
