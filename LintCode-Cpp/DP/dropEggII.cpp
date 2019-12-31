/* 
584. Drop Eggs II

There is a building of n floors. If an egg drops from the k th floor or above, it will break. If it's dropped from any floor below, it will not break.

You're given m eggs, Find k while minimize the number of drops for the worst case. Return the number of drops in the worst case.

Example
Example 1:

Input: m = 2, n = 100 
Output: 14
Example 2:

Input: m = 2, n = 36 
Output: 8
*/

class Solution {
public:
    /**
     * @param m: the number of eggs
     * @param n: the number of floors
     * @return: the number of drops in the worst case
     */
    int dropEggs2(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //initialize
        for(int i = 1; i <= m; i++)
        {
            dp[i][1] = 1; 
        }
        
        for(int j = 1; j <= n; j++)
        {
            dp[1][j] = j;
        }
        
        for(int i = 2; i <= m; i++)
        {
            for(int j = 2; j <= n; j++)
            {
                dp[i][j] = INT_MAX;
                // drop the first egg at kth floor 
                // when we have i eggs in a building with j floors
                for(int k = 1; k <= j; k++)
                {
                    // if egg broke at kth floor, subproblem = i-1 eggs with k-1 floors
                    // if egg did not break, subproblem = i eggs with j-k floors
                    // we do not know if it will break in advance, so max()
                    // try all possible floor to find the optimal k with min drops 
                    dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][k-1], dp[i][j-k]));
                }
            }
        }
        return dp[m][n];
        
    }
};