/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_clues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrishan <mkrishan@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:19:39 by mkrishan          #+#    #+#             */
/*   Updated: 2026/07/25 13:58:55 by mkrishan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	check_visible(int arr[SIZE]);

int	valid_clues(void)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		cols_from_grid(col, TRUE, arr);
		if (clues[i] != 0 && check_visible(arr) != clues[i])
			return (0);
		cols_from_grid(col, FALSE, arr);
		if (clues[i + SIZE] != 0 && check_visible(arr) != clues[i + SIZE])
			return (0);
		rows_from_grid(row, TRUE, arr);
		if (clues[i + (SIZE * 2)] != 0 && check_visible(arr) != clues[i + (SIZE * 2)])
			return (0);
		rows_from_grid(row, FALSE, arr);
		if (clues[i + (SIZE * 3)] != 0 && check_visible(arr) != clues[i + (SIZE * 3)])
			return (0);
		i++;
	}
	return (1);
}
