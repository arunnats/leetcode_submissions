class Solution {
public:
    int totalNQueens(int n) 
    {
        int ans = 0;
        vector<string> board(n, string(n, '.')); 

        return backtrack(ans, board, 0, n);
    }

    int backtrack(int ans, vector<string>& board, int row, int n)
    {
        if(row == n)
        {
            return ans + 1;
        }

        for(int col = 0 ; col < n; col++)
        {
             if (isSafe(board, row, col, n)) 
             {
                board[row][col] = 'Q';  
                ans = backtrack(ans, board, row + 1, n); 
                board[row][col] = '.';  
            }
        }

        return ans;
    }

    bool isSafe(vector<string>& board, int row, int col, int n)
    {
        for (int i = 0; i < row; ++i) 
        {
            if (board[i][col] == 'Q') 
                return false;
        }

        //upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') 
                return false;
        }

        //upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') 
                return false;
        }

        return true;
    }
};