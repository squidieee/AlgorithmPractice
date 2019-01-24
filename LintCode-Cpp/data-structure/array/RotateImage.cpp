/* 
161. Rotate Image
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Example
Given a matrix

[
    [1,2],
    [3,4]
]
rotate it by 90 degrees (clockwise), return

[
    [3,1],
    [4,2]
]
Challenge
Do it in-place.
*/

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        // not in place
        /*
        vector<vector<int>> temp = matrix;
        int n = matrix.size();
        for(int i = 0; i < temp.size(); i++)
        {
            for(int j = 0; j < temp[0].size(); j++)
            {
                matrix[j][n - 1 - i] = temp[i][j];
            }
        }
        */
        
        int n = matrix.size();
        for(int i = 0; i < n/2; i++)
        {
            for(int j = i; j < n - 1 - i; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
        
    }
};

// 1st row -> last column
// ...
// last row -> first column

// (0,0) -> (0,2)
// (0,1) -> (1,2)
// (0,2) -> (2,2)

// new index i = old j
// new index j = n - 1 - old_i

// if in place:
// swapping four corners clockwise
// notice that the i < n/2 since we should not modify the values that have been modified
// by the first few numbers in the same row
// keep swapping four corners until meeting the center of image, edge will be smaller and smaller