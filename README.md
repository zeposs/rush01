create_grid()
{
    grid = malloc(sizeof () * 4);
    if !grid
        return (NULL);
}

clues[0-3] - top
clues[4-7] - bottom
clues[8-11] - left
clues[12-16] - right

int check_valid_input(row, col, value)
{
    while (col < 4)
    {
        if value exists in row;
            return (0);
        col++;
    }
    while (row < 4)
    {
        if value exists in column;
            return (0);
        row++;
    }
    return (1);
}

int check_row(row)
{

}

int check_col(col)
{

}

int count_towers(value)
{
    int visible;
    int tallest;

    visible = 0;
    if value <= 4
    {
        if (value > tallest)
        {
            tallest = value;
            visible++;
        }
    }
}



#include <unistd.h>

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
int main(int argc, char *argv[])
{
    int clues[16];
    if (argc == 2 && check_valid_argv(argv[1], clues))
    {
        write(1, "Pass", 4);
        return (0);
    }
    else
        write(1, "Error", 5);
    return (0);
}
