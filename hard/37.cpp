/*

Copyright 2026 Jared Robert Wright

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

char testboard[9][9] = {
	{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};

char testboard2[9][9] = {
	{'.','.','9','7','4','8','.','.','.'},
	{'7','.','.','.','.','.','.','.','.'},
	{'.','2','.','1','.','9','.','.','.'},
	{'.','.','7','.','.','.','2','4','.'},
	{'.','6','4','.','1','.','5','9','.'},
	{'.','9','8','.','.','.','3','.','.'},
	{'.','.','.','8','.','3','.','2','.'},
	{'.','.','.','.','.','.','.','.','6'},
	{'.','.','.','2','7','5','9','.','.'}
};

bool guess(int boardstate[9][9]);
bool iterate(int boardstate[9][9]);

bool guess(int boardstate[9][9])
{
	return false;
}

//return true if valid
bool iterate(int boardstate[9][9])
{
	bool solved = false;
	bool changed = false;

	//this is as simple as it gets - keep cycling through all cells until it naturally converges on a valid solution by eliminating all other possibilities
	while (!solved)
	{
		solved = true;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				//check if value known
				switch (boardstate[i][j])
				{
				case 1:
				case 2:
				case 4:
				case 8:
				case 16:
				case 32:
				case 64:
				case 128:
				case 256:
					for (int k = 0; k < 9; k++)
					{
						if (j != k)
						{
							changed = true;
							boardstate[i][k] &= ~(boardstate[i][j]);
						}
						if (i != k)
						{
							changed = true;
							boardstate[k][j] &= ~(boardstate[i][j]);
						}
					}
					for (int k = 0; k < 3; k++)
					{
						for (int h = 0; h < 3; h++)
						{
							int row = i - (i % 3) + k;
							int col = j - (j % 3) + h;
							if (i != row && j != col)
							{
								changed = true;
								boardstate[row][col] &= ~(boardstate[i][j]);
							}
						}
					}
					break;

				default:
					solved = false;
				}
			}
		}

		if (!changed)
		{
			guess(boardstate);
		}
	}

	return false;
}

void solveSudoku(char board[9][9], int boardSize, int* boardColSize)
{
	bool solved = false;
	bool changed = false;

	int boardstate[9][9];

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.')
			{
				boardstate[i][j] = 511;
			}
			else
			{
				boardstate[i][j] = 1 << (board[i][j] - '1');
			}
		}
	}

	//this is as simple as it gets - keep cycling through all cells until it naturally converges on a valid solution by eliminating all other possibilities
	while (!solved)
	{
		solved = true;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				//check if value known
				switch (boardstate[i][j])
				{
				case 1:
				case 2:
				case 4:
				case 8:
				case 16:
				case 32:
				case 64:
				case 128:
				case 256:
					for (int k = 0; k < 9; k++)
					{
						if (j != k)
						{
							changed = true;
							boardstate[i][k] &= ~(boardstate[i][j]);
						}
						if (i != k)
						{
							changed = true;
							boardstate[k][j] &= ~(boardstate[i][j]);
						}
					}
					for (int k = 0; k < 3; k++)
					{
						for (int h = 0; h < 3; h++)
						{
							int row = i - (i % 3) + k;
							int col = j - (j % 3) + h;
							if (i != row && j != col)
							{
								changed = true;
								boardstate[row][col] &= ~(boardstate[i][j]);
							}
						}
					}
					break;

				default:
					solved = false;
				}
			}
		}

		if (!changed)
		{
		}
	}
	//convert state back to board data
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			switch (boardstate[i][j])
			{
			case 1:
				board[i][j] = '1';
				break;

			case 2:
				board[i][j] = '2';
				break;

			case 4:
				board[i][j] = '3';
				break;

			case 8:
				board[i][j] = '4';
				break;

			case 16:
				board[i][j] = '5';
				break;

			case 32:
				board[i][j] = '6';
				break;

			case 64:
				board[i][j] = '7';
				break;

			case 128:
				board[i][j] = '8';
				break;

			case 256:
				board[i][j] = '9';
				break;

			default:
				break;
			}
		}
	}
}