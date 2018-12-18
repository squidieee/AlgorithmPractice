/* 
28. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example
Consider the following matrix:

[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
Given target = 3, return true.

Challenge
O(log(n) + log(m)) time
*/

class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int start(0), end(m * n - 1);
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            int row = mid / n;
            int col = mid % n;
            if (target >  matrix[row][col])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        if (matrix[start/n][start%n] == target || matrix[end/n][end%n] == target) 
            return true;
        return false;
    }
    
    
    // linear search: O(mn)
    // binary search as a 1D array: O(log(mn)) = O(logm + logn)
};