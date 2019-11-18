/* 
1375. Substring With At Least K Distinct Characters

Given a string S with only lowercase characters.

Return the number of substrings that contains at least k distinct characters.

Example
Example 1:

Input: S = "abcabcabca", k = 4
Output: 0
Explanation: There are only three distinct characters in the string.
Example 2:

Input: S = "abcabcabcabc", k = 3
Output: 55
Explanation: Any substring whose length is not smaller than 3 contains a, b, c.
    For example, there are 10 substrings whose length are 3, "abc", "bca", "cab" ... "abc"
    There are 9 substrings whose length are 4, "abca", "bcab", "cabc" ... "cabc"
    ...
    There is 1 substring whose length is 12, "abcabcabcabc"
    So the answer is 1 + 2 + ... + 10 = 55.
Notice
10 ≤ length(S) ≤ 1,000,000
1 ≤ k ≤ 26
*/

class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: the number of substrings there are that contain at least k distinct characters
     */
    long long kDistinctCharacters(string &s, int k) {
        if (k > s.size()) return 0;
        
        int end = 0;
        long long cnt = 0;
        unordered_map<char, int> map;
        for(int start = 0; start < s.size() - k + 1; start++ )
        {
            end = max(end, start);
            while(end < s.size() && map.size() < k)
            {
                map[s[end]]++;
                end++;
            }
            
            if (map.size() >= k)
            {
                cnt += (int)s.size() - end + 1;
            }
            
            map[s[start]]--;
            if (map[s[start]] == 0) map.erase(s[start]);
        }
        
        return cnt;
    }
};

// Sol1: brutal force 
// O(n^2) 
// start at 0, move end from k-1 to s.size() - 1
// once find, no need to proceed but sum up all sols
// then move start++, move end again

// Sol2: reuse the map
// begin goes from 0 to n-1 in total
// end goes from 0 to n-1 in total
// O(n + n) = O(n)