/*
33. N-Queens
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example
There exist two distinct solutions to the 4-queens puzzle:

[
  // Solution 1
  [".Q..",
   "...Q",
   "Q...",
   "..Q."
  ],
  // Solution 2
  ["..Q.",
   "Q...",
   "...Q",
   ".Q.."
  ]
]
Challenge
Can you do it without recursion?
*/



class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        if (n==0)
        {
            results.push_back(vector<string>());
            return results;
        }
        
        vector<bool> visited(n, false);
        vector<int> subset;
        
        dfs(n, visited, subset, results);
        
        return results;
    }
    
    // generate a permutation
    // take a componenet from 0: n, add it to the subset if valid
    // if subset.size() == n, create formatted solution and push it to results
    
    void dfs(int n, vector<bool>& visited, vector<int>& subset, vector<vector<string>>& results)
    {
        for( int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            
            if (!isValid(subset, i)) // trim
                continue;
            
            subset.push_back(i);
            visited[i] = true;
            
            if( subset.size() == n )
            {
                addSubsetToResult(subset, results);
            }
            else
            {
                dfs(n, visited, subset, results);
            }
            
            subset.pop_back();
            visited[i] = false;
        }
    }
    
    bool isValid(const vector<int>& cols, int newCol)
    {
        if (cols.empty()) return true;
        
        int newRow = cols.size();
        
        for(int i = 0; i < cols.size(); i++)
        {
            // (i, cols[i]) <=> (newRow, newCol)
            if (std::abs(newRow - i) == std::abs(newCol - cols[i]))
                return false;
        }
        return true;
    }
    
    void addSubsetToResult(const vector<int>& cols, vector<vector<string>>& results)
    {
        vector<string> oneResult;
        for(int row = 0; row < cols.size(); row++)
        {
            string rowString;
            for(int col = 0; col < cols.size(); col++)
            {
                if (col == cols[row])
                    rowString += "Q";
                else
                    rowString += ".";
            }
            oneResult.push_back(rowString);
        }
        results.push_back(oneResult);
    }
};