/* 

200. Longest Palindromic Substring
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Example
Given the string = "abcdzdcab", return "cdzdc".

Challenge
O(n2) time is acceptable. Can you do it in O(n) time.

*/

class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        if (s.empty() || s.length() == 1) return s;
        
        int start(0), max_len(1);
        for (int j = s.length() - 1; j > 0; j--)
        {
            for (int i = 0; i < j - max_len + 1; i++)
            {
                if( isPalindrome( s.substr(i, j - i + 1) ))
                {
                    start = i;
                    max_len =  j - i + 1;
                }
            }
        }
        
        return s.substr(start, max_len);
    }
    
    bool isPalindrome(const string &s) // O(length(s))
    {
        if (s.empty()) return true;
        if (s.length()==1) return true;
        
        int start(0), end(s.length()-1);
        while(start <= end)
        {
            if (s[start] == s[end]) 
            {
                start ++;
                end --;
            }
            else
                return false;
        }
        return true;
    }
};