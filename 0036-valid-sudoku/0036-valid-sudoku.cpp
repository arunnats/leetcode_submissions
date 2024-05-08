class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_map<char, int> nineMap;

        for(int i = 0; i < 9; i++)
        {
            nineMap.clear();

            for(int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') 
                    continue;

                nineMap[ board[i][j] ] ++;
                if(nineMap[ board[i][j] ] > 1)
                    return false;
            }
        }

        for(int i = 0; i < 9; i++)
        {
            nineMap.clear();

            for(int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.') 
                    continue;

                nineMap[ board[j][i] ] ++;
                if(nineMap[ board[j][i] ] > 1)
                    return false;
            }
        }

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                nineMap.clear();

                for(int l = 0; l < 3; l++)
                {
                    for(int m = 0; m < 3; m++)
                    {
                        if (board[l+3*i][m+3*j] == '.') 
                            continue;

                        nineMap[ board[l+3*i][m+3*j] ]++;
                        if(nineMap[ board[l+3*i][m+3*j] ] > 1)
                            return false;
                    }
                }               

            }
        }


        return true;
    }
};