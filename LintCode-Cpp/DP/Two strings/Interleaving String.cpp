/* 
29. Interleaving String

Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.

Example
Example 1:

Input:
"aabcc"
"dbbca"
"aadbbcbcac"
Output:
true
Example 2:

Input:
""
""
"1"
Output:
false
Example 3:

Input:
"aabcc"
"dbbca"
"aadbbbaccc"
Output:
false
Challenge
O(n2) time or better


*/

class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        int i1(0), i2(0), i3(0);
        unordered_map<char, int> candidates;
        if(s1.size() > 0) candidates[s1[0]]++;
        if(s2.size() > 0) candidates[s2[0]]++;
        
        while(i3 < s3.size() && candidates[s3[i3]] > 0)
        {
            candidates[s3[i3]]--;
            
            if(i1 < s1.size() && i2 < s2.size() && s1[i1] == s2[i2])
            {
                if(++i1 < s1.size()) candidates[s1[i1]]++;
                if(++i2 < s2.size()) candidates[s2[i2]]++;
            }
            else if(i1 < s1.size() && s1[i1] == s3[i3])
            {
                i1++;
                if(i1 < s1.size()) candidates[s1[i1]]++;
            }
            else if(i2 < s2.size() && s2[i2] == s3[i3])
            {
                i2++;
                if(i2 < s2.size()) candidates[s2[i2]]++;
            }
            i3++;
        }
        
        
        return i1 == s1.size() && i2 == s2.size() && i3 == s3.size();
    }
};

// O(n)
// candidates pool is a hash map 

// for each char in s3
// see if it is in the pool
// if exist, put the next char of s1 or s2 into the pool
// if not, s3 is not an interleaving string
// when chars in s1 and s2 are equal
// put next chars in both s1 and s2 into the pool

// dp: O(n^2)
// dp[i][j] represents whether s1(0~i) and s2(0~j) can interleave s2(0~i+j)
// dp[i][j] = dp[i-1][j] when s1[i] == s3[i+j] ||
//            dp[i][j-1] when s2[j] == s3[i+j]
