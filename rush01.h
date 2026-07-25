/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrishan <mkrishan@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:39:12 by mkrishan          #+#    #+#             */
/*   Updated: 2026/07/25 14:58:46 by mkrishan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RUSH01_H
# define RUSH01_H

#include <unistd.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define SIZE 4

int	rows_from_grid(int row, int view_point, int arr[SIZE]);
int	cols_from_grid(int col, int view_point, int arr[SIZE]);

int	check_visible(int arr[SIZE]);
int	valid_clues(void);

int	check_dup(int row, int col, int nbr);

int	display_grid(int **grid);

#endif
