/* 
944. Maximum Submatrix
Given an n x n matrix of positive and negative integers, find the submatrix with the largest possible sum.

Example
Given matrix = 
[
[1,3,-1],
[2,3,-2],
[-1,-2,-3]
]
return 9.
Explanation:
the submatrix with the largest possible sum is:
[
[1,3],
[2,3]
]
*/

class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: the largest possible sum
     */
    int maxSubmatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) return 0;
        if ( matrix.size() != matrix[0].size() ) return -1; // invalid arg
        
        // first compute prefix sum columnwise
        vector<vector<int>> prefixColSums(matrix.size());
        for(int i = 0; i < matrix.size(); i++)
        {
            prefixColSums[i].resize(matrix[0].size());
            for(int j = 0; j < matrix[0].size(); j++)
            {
                prefixColSums[i][j] = matrix[i][j];
                if (i > 0)
                    prefixColSums[i][j] += prefixColSums[i-1][j];
            }
        }
        
        int maxNum = INT_MIN;
        
        for (int top = 0; top < matrix.size(); top++)
        {
            for(int bottom = top; bottom < matrix.size(); bottom++)
            {
                // get the columnwise sums between top and bottom
                vector<int> colSums(matrix[0].size());
                for(int i = 0; i < matrix[0].size(); i++)
                {
                    colSums[i] = prefixColSums[bottom][i];
                    if (top > 0)
                        colSums[i] -= prefixColSums[top-1][i];
                }
                
                int topBottomMax = subarrayMaxSum(colSums);
                maxNum = maxNum > topBottomMax? maxNum: topBottomMax;
                cout << maxNum << endl;
            }
        }
        
        return maxNum;
        
    }
    
    int subarrayMaxSum(vector<int>& array)
    {
        int max = INT_MIN;
        int sum = 0;
        int minPrefix = 0;
        for(int i = 0; i < array.size(); i++)
        {
            sum += array[i];
            int sub = sum - minPrefix;
            max = sub > max? sub:max;
            minPrefix = sum < minPrefix? sum: minPrefix;
        }
        
        return max;
    }
    
    // add a top and bottom line; compute col sum of all elements within two lines vertically
    // this will give a 1d array representing all prefix sums for any sub matrices start with the top
    // and end with the bottom
    // then find the 1d prefix sum of the 1d array 
    // Time O(n^3)
    // Col sums can be pre caomputed
};