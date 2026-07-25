/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:08:18 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/07/25 18:43:47 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

//Set size of matrix


//checking if the rows/column has duplicates
int check_dup(int row, int col, int nbr, int grid[SIZE][SIZE])
{
    int i = 0;
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
void rows_from_grid(int row, int view_point, int arr[SIZE], int grid[SIZE][SIZE])
{
    int i = 0;
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
void cols_from_grid(int col, int view_point, int arr[SIZE], int grid[SIZE][SIZE])
{
    int i = 0;
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
int check_visible(int arr[SIZE])
{
    int i = 0;
    int visible;
    int tallest;

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

int check_valid_argv(char *argv, int *clues)
{
    int i;
    int index;
    
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
void(init_grid(int grid[SIZE][SIZE]))
{
    int row;
    int col;

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

int main(int argc, char *argv[])
{
    int clues[SIZE * SIZE];
    int grid[SIZE][SIZE];
    int arr[SIZE];
    
    init_grid(grid);
    if (argc == 2 && check_valid_argv(argv[1], clues))
        write(1, "Pass\n\n", 6);
    else
        write(1, "Error", 5);

    if (backtrack(grid, 0, 0, arr, clues))
        display_grid(grid);
    else
        write(1, "Error", 5);
    return (0);
}