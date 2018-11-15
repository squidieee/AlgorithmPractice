/*
34. N-Queens II
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

Example
For n=4, there are 2 distinct solutions.
*/

class Solution {
public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        if (n == 0) return 0;
        
        vector<bool> visited(n, false);
        vector<int> subset;
        
        int result(0);
    
        dfs(n, visited, subset, &result);
        return result;
    }
    
    void dfs(int n, vector<bool>& visited, vector<int>& subset, int* result)
    {
        for(int i = 0; i < n; i++)
        {
            if(visited[i])
                continue;
            
            if(!isValid(subset, i))
                continue;
            
            subset.push_back(i);
            visited[i] = true;
            
            if(subset.size() == n)
            {
                (*result)++;
            }
            else
            {
                dfs(n, visited, subset, result);
            }
            
            subset.pop_back();
            visited[i]=false;
        }
    }
    
    bool isValid(vector<int>& cols, int col)
    {
        if (cols.empty()) return true;
        
        int row = cols.size();
        for (int i = 0; i < cols.size(); i++)
        {
            // (i, cols[i]) vs. (row, col)
            if (std::abs(i - row) == std::abs(cols[i]-col))
                return false;
        }
        return true;
    }
};