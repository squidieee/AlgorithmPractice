/* 
665. Range Sum Query 2D - Immutable
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Example
Given matrix =

[
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12

Notice
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        _prefix.resize(matrix.size());
        for(int i = 0; i < matrix.size(); i++)
        {
            _prefix[i].resize(matrix[0].size());
            int rowSum = 0;
            for(int j = 0; j < matrix[0].size(); j++)
            {
                rowSum += matrix[i][j];
                _prefix[i][j] = rowSum;
                if (i > 0)
                    _prefix[i][j] += _prefix[i-1][j]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) return _prefix[row2][col2];
        if (row1 == 0) return _prefix[row2][col2] - _prefix[row2][col1 - 1];
        if (col1 == 0) return _prefix[row2][col2] - _prefix[row1 - 1][col2];
        return _prefix[row2][col2] - _prefix[row1-1][col2] - _prefix[row2][col1-1] + _prefix[row1-1][col1-1];
    }
    
private:
    
    vector<vector<int>> _prefix;
    
};

// Time O(n^2) Space O(n^2)

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */