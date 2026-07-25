/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:39:12 by mkrishan          #+#    #+#             */
/*   Updated: 2026/07/25 18:43:31 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

#include <unistd.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SIZE 4

int	backtrack(int grid[SIZE][SIZE], int row, int col, int arr[SIZE], int clues[SIZE * SIZE]);
void	rows_from_grid(int row, int view_point, int arr[SIZE], int grid[SIZE][SIZE]);
void	cols_from_grid(int col, int view_point, int arr[SIZE], int grid[SIZE][SIZE]);

int	check_visible(int arr[SIZE]);
int	valid_clues(int row, int col, int arr[SIZE], int clues[SIZE * SIZE], int grid[SIZE][SIZE]);

int	check_dup(int row, int col, int nbr, int grid[SIZE][SIZE]);

void	display_grid(int grid[SIZE][SIZE]);

#endif
