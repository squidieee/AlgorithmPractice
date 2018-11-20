/*

123. Word Search
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example
Given board =

[
  "ABCE",
  "SFCS",
  "ADEE"
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/



class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>> &board, string &word) {
        if (board.empty()) return false;
        if (word.empty()) return false;
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        bool result = false;
        for(int i = 0;i<board.size();i++)
        {
            for( int j = 0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                    result = dfs(board, word, 0, i, j, visited);
                if (result) return true;
            }
        }
        return result;
    }
    
    // take a char from word, check if any one of four directions match the char (if valid)
    // if match => recursion to that point
    // record the path of visited using a bool array
    // back trace to go other directions

    bool dfs(const vector<vector<char>> &board, const string &word, int iword, int x, int y, vector<vector<bool>>& visited)
    {
        if (board[x][y] != word[iword]) return false;
        if (iword == word.size() - 1) return true;
        
        bool result = false;
        
        for(int i = 0; i < 4; i++)
        {
            int nextX = dirX[i] + x;
            int nextY = dirY[i] + y;
            
            if (!isValid(board, nextX, nextY)) continue;
            if (visited[nextX][nextY]) continue;
            
            visited[x][y] = true;
            
            if (word[iword + 1] == board[nextX][nextY])
            {
                result = result || dfs(board, word, iword + 1, nextX, nextY, visited);
            }
            visited[x][y] = false;
        }
        return result;
    }
    
    bool isValid(const vector<vector<char>> &board, int row, int col)
    {
        if (row >= 0 && row < board.size() && col >=0 && col < board[0].size()) return true;
        return false;
    }
    
    private:
    int dirX[4] = {-1, 0, 1, 0};
    int dirY[4] = {0, 1, 0, -1};
};