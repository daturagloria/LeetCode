class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int size = board.size();
        vector<int> count;

        for (int i = 0; i < size; i++)
        {
            count.assign(size, 0);
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] != '.')
                {
                    int pos = board[i][j] - '1';
                    if (count[pos] != 0)
                        return false;
                    else
                        count[pos]++;
                }
            }
        }

        for (int j = 0; j < size; j++)
        {
            count.assign(9, 0);
            for (int i = 0; i < size; i++)
            {
                if (board[i][j] != '.')
                {
                    int pos = board[i][j] - '1';
                    if (count[pos] != 0)
                        return false;
                    else
                        count[pos]++;
                }
            }
        }

        for (int i = 0; i < size; i += 3)
        {
            for (int j = 0; j < size; j += 3)
            {
                count.assign(9, 0);
                for (int row = i; row < i + 3; row++)
                    for (int col = j; col < j + 3; col++)
                    {
                        if (board[row][col] != '.')
                        {
                            int pos = board[row][col] - '1';
                            if (count[pos] != 0)
                                return false;
                            else
                                count[pos]++;
                        }
                    }
            }
        }

        return true;
    }
};