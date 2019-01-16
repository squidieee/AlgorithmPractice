/* 
627. Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Example
Given s = "abccccdd" return 7

One longest palindrome that can be built is "dccaccd", whose length is 7.

Notice
Assume the length of given string will not exceed 1010.

*/

class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        // write your code here
        if (s.empty())
         return 0;
        
        int n = s.size();
        if (n==1)
            return 1;
        
        std::unordered_map<char, int> map;
        for(int i = 0; i < n ; i++)
        {
            if(map.count(s[i]) > 0)
            {
                map.at(s[i]) += 1;
            }
            else
                map.insert( {s[i], 1} );
        }
        
        int len = 0;
        bool hasOdd = false;
        
        for(auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second % 2 == 0)
                len += it->second;
            else
            {
                if (it->second > 1)
                    len += it->second - 1;
                hasOdd = true;
            }
        }
        
        if (hasOdd) len++;
        return len;
    }
};