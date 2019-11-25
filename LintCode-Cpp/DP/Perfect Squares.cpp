/* 
513. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example
Example 1:

Input: 12
Output: 3
Explanation: 4 + 4 + 4
Example 2:

Input: 13
Output: 2
Explanation: 4 + 9
*/

class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: An integer
     */
    int numSquares(int n) {
        if (n == 0) return 0;
        vector<int> fn(n, INT_MAX);
        
        fn[0] = 1;
        for(int i = 1; i < n ; i++)
        {
            int num = std::sqrt(i + 1);
            if (num * num == i + 1)
            {
                fn[i] = 1;
                continue;
            }
            
            for(int j = 0; j < (i + 1)/2; j++)
            {
                fn[i] = std::min(fn[i], fn[j] + fn[i - j - 1]);
            }
        }
        
        return fn.back();
    }
};

// dp
// num = sqrt(f[n])
// if num * num == f[n] then 1
// f[n] = arg min (f[i] + f[j]), where i + j = n
// O(n^2)

// improvement: 
// dp[i] = arg min(dp[i], dp[i - j * j] + 1), where j * j <= i
// O(n^(3/2))