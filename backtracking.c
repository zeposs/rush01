int	backtrack(int board[4][4], int row, int col)
{
	int	value;
	int next_row;
	int next_col;

	if (row == 4)
		return (1);

	next_row = row;
	next_col = col + 1;
	if (next_col == 4)
	{
		next_col = 0;
		next_row++;
	}

	value = 1;
	while (value <= 4)
	{
		if (/* is_valid function call here*/)
		{
			board[row][col] = value;

			if (backtrack(board, next_row, next_col))
				return (1);

			board[row][col] = 0;
		}
		value++;
	}
	return (0);
}