/* 
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen(0), start(0);
        for(int i = 0; i < s.length(); i++)
        {
            int l1 = longestFromCenter(s, i, i);
            int l2 = longestFromCenter(s, i, i+1);
            int li = max(l1, l2);
            if (li > maxlen)
            {
                start = l1>l2? i-(l1-1)/2: i-l2/2+1;
                maxlen = li;
            }
        }
        return s.substr(start, maxlen);
    }
    
    int longestFromCenter(string s, int k1, int k2)
    {
        int i = k1;
        int j = k2;
        int L = s.length();
        int sz = 0;
        while(i >=0 && j < L )
        {
            if (s[i] != s[j])
               break;
            sz = j - i + 1;
            i--;
            j++;
        }
        return sz;
    }
};