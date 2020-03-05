/* 
77. Longest Common Subsequence

Given two strings, find the longest common subsequence (LCS).

Your code should return the length of LCS.

Example
Example 1:
	Input:  "ABCD" and "EDCA"
	Output:  1
	
	Explanation:
	LCS is 'A' or  'D' or 'C'


Example 2:
	Input: "ABCD" and "EACB"
	Output:  2
	
	Explanation: 
	LCS is "AC"
Clarification
What's the definition of Longest Common Subsequence?

https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
http://baike.baidu.com/view/2020307.htm

*/

class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        if(A.empty() || B.empty()) return 0;
        int m = A.size();
        int n = B.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dp[i][j] = max(i > 0 ? dp[i-1][j]: 0, j > 0? dp[i][j-1]: 0);
                if( A[i] == B[j] ) 
                {
                    dp[i][j] = (i > 0 && j > 0 ? dp[i-1][j-1]: 0) + 1; 
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};