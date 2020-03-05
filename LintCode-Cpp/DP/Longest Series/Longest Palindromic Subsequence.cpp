/* 
667. Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example
Example1

Input: "bbbab"
Output: 4
Explanation:
One possible longest palindromic subsequence is "bbbb".
Example2

Input: "bbbbb"
Output: 5
*/

class Solution {
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    int longestPalindromeSubseq(string &s) {
        if(s.size() <= 1) return s.size();
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        
        for(int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
            if(i < s.size() - 1) dp[i][i + 1] = (s[i] == s[i + 1]) ? 2:1;
        }
        
        for(int len = 3; len <= s.size(); len++)
        {
            for(int start = 0; start <= s.size() - len; start++)
            {
                int end = start + len - 1;
                if(s[start] == s[end])
                    dp[start][end] = 2 + dp[start + 1][end - 1];
                else
                    dp[start][end] = max(dp[start][end-1], dp[start+1][end]);
            }
        }
        
        return dp[0][s.size() - 1];
    }
};