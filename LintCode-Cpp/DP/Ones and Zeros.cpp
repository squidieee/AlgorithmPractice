/* 
668. Ones and Zeroes

In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Example
Example1

Input:
["10", "0001", "111001", "1", "0"]
5
3
Output: 4
Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are "10", "0001", "1", "0"
Example2

Input:
["10", "0001", "111001", "1", "0"]
7
7
Output: 5
Explanation: All strings can be formed by the using of 7 0s and 7 1s.
Notice
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
*/

class Solution {
public:
    /**
     * @param strs: an array with strings include only 0 and 1
     * @param m: An integer
     * @param n: An integer
     * @return: find the maximum number of strings
     */
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for(int k = 1; k <= strs.size(); k++)
        {
            int ones = 0;
            int zeros = 0;
            for(char ch: strs[k-1])
            {
                if(ch == '0') zeros++;
                else ones++;
            }
            
            for(int i = 0; i <= m; i++)
            {
                for(int j = 0; j <= n; j++)
                {
                    //dp[k][i][j] = max(dp[k][i][j-1], dp[k][i-1][j]);
                    dp[k][i][j] = dp[k-1][i][j]; 

                    if(i >= zeros && j >= ones)                    
                        dp[k][i][j] = max(dp[k][i][j], 
                                  dp[k-1][i - zeros][j - ones] + 1);
                }
            }
        }
        
        return dp[strs.size()][m][n];
    }
};