#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define SIZE 4

//Set size of matrix
int grid[SIZE][SIZE];
int clues[SIZE * SIZE];

//checking if the rows/column has duplicates
int check_dup(int row, int col, int nbr)
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
void rows_from_grid(int row, int view_point, int arr[SIZE])
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
void cols_from_grid(int col, int view_point, int arr[SIZE])
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