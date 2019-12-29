/* 
581. Longest Repeating Subsequence

Given a string, find length of the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any ith character in the two subsequences shouldn’t have the same index in the original string.

Example
Example 1:

Input:"aab"
Output:1
Explanation:
The two subsequence are a(first) and a(second). 
Note that b cannot be considered as part of subsequence as it would be at same index in both.
Example 2:

Input:"abc"
Output:0
Explanation:
There is no repeating subsequence
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: the length of the longest repeating subsequence
     */
    int longestRepeatingSubsequence(string &str) {
        if(str.size() < 2) return 0;
        
        int len = str.size();
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        for(int i = 2; i < len + 1; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if( str[i-1] == str[j-1] )
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[len][len - 1];
    }

};

// similar to Lintcode 77. LCS
// dp[i][j] represents longest subsequence between two string: 
// substr1 from 0 to i
// substr2 from 0 to j
// where j < i 
// we compare the last char in substr1 with substr2
// if substr1.back() == substr2.back():
// dp[i][j] = dp[i - 1][j - 1] + 1
// if not equal
// dp[i][j] = max(dp[i][j-1], dp[i-1][j])