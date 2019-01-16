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
        
        int start(0), longest(1);
        for(int i = 0; i < s.length(); i++)
        {
            int len = findlongestFromCenter(s, i, i); // odd
            if (len > longest)
            {
                longest = len;
                start = i - (len - 1) / 2;
            }
            
            len = findlongestFromCenter(s, i, i+1); // even
            if (len > longest)
            {
                longest = len;
                start = i - len / 2 + 1;
            }
        }
        
        return s.substr(start, longest);

    }
    
    int findlongestFromCenter(const string &s, int mid1, int mid2) 
    {
        int len(1);
        while(mid1 >=0 && mid2 < s.length())
        {
            if (s[mid1] == s[mid2])
            {
                len = mid2 - mid1 + 1;
                mid1--;
                mid2++;
            }
            else
                return len;
        }
        return len;
    }
};