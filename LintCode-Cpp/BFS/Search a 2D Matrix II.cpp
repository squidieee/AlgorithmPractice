/*
38. Search a 2D Matrix II
Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.

This matrix has the following properties:

Integers in each row are sorted from left to right.
Integers in each column are sorted from up to bottom.
No duplicate integers in each row or column.
Example
Example 1:

Input:
	[[3,4]]
	target=3
Output:1
Example 2:

Input:
    [
      [1, 3, 5, 7],
      [2, 4, 7, 8],
      [3, 5, 9, 10]
    ]
    target = 3
Output:2
Challenge
O(m+n) time and O(1) extra space
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> coordQ;
        coordQ.push(std::make_pair(m-1, 0));
        visited[m-1][0] = true;
        
        int cnt = 0;
        while(!coordQ.empty())
        {
            pair<int, int> curr = coordQ.front();
            coordQ.pop();
            
            if(matrix[curr.first][curr.second] == target) cnt++;

            if(matrix[curr.first][curr.second] >= target && 
               curr.first != 0 && !visited[curr.first - 1][curr.second])
            {
                coordQ.push(std::make_pair(curr.first - 1, curr.second));
                visited[curr.first - 1][curr.second] = true;
            }
            
            if(matrix[curr.first][curr.second] <= target &&
               curr.second != n-1 && !visited[curr.first][curr.second + 1])
            {
                coordQ.push(std::make_pair(curr.first, curr.second + 1));
                visited[curr.first][curr.second + 1] =  true;
            }
        }
        
        return cnt;
    }
};

// bfs:
// left bottom to right top