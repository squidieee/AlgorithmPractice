/*
433. Number of Islands
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Find the number of islands.

Example
Given graph:

[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]
return 3.
 */
 class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        int cnt(0);
        
        for(int i = 0 ; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == false)
                    continue;
                bfsFrom(grid, i ,j); // it will modify the original matrix
                cnt++;
            }
        }
        return cnt;
    }
    
    bool isValid (vector<vector<bool>> &grid, int row, int col)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (row >= rows || row < 0) return false;
        if (col < 0 || col >= cols) return false;
        return grid[row][col];
    }
    
    void bfsFrom(vector<vector<bool>> &grid, int row, int col)
    {
        queue<pair<int,int>> q;
        q.push(make_pair(row, col));
        
        while(!q.empty())
        {
            pair<int,int> temp = q.front();
            q.pop();
            grid[temp.first][temp.second] = false;
            for(auto dir : _directions)
            {
                pair<int,int> new_dir = make_pair(temp.first + dir.first, temp.second + dir.second);
                if (!isValid(grid, new_dir.first, new_dir.second))
                    continue;
                q.push(new_dir);
            }
        }
    }
    
private:
    vector<pair<int,int>> _directions {{-1,0}, {1,0},{0,-1},{0,1}};
};