/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:35:00 by mkrishan          #+#    #+#             */
/*   Updated: 2026/07/25 17:04:59 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	display_grid(int grid[SIZE][SIZE])
{
	int	row;
	int	col;
	char	c;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < (SIZE - 1))
			{
				write(1, " ", 1);
			}
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
