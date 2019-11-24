/* 
512. Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Example
Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as AB (1 2) or L (12).
Example 2:

Input: "10"
Output: 1
*/

class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        if (s.size() == 0) return 0;
        
        vector<int> f1(s.size(), 0);
        vector<int> f2(s.size(), 0);
        f1[0] = s[0] != '0'? 1 : 0;
        f2[0] = 0;
        for(int i = 1; i < s.size(); i++)
        {
            f1[i] = s[i] != '0' ? f1[i-1] + f2[i-1] : 0;
            f2[i] = validCode(s, i-1) ? f1[i - 1] : 0; 
        }
        
        return f1[s.size() - 1] + f2[s.size() - 1];
    }
    
    /* // DFS: TLE
    int numDecodings(string &s) {
        int result = 0;
        dfs(s, 0, result);
        return result;
    }
    
    void dfs(string &s, int start, int& result)
    {
        if (start == s.size() && start != 0) result++;
        
        if (start >= s.size()) return;
        if (s[start] == '0') return;
        
        string sub = s.substr(start, 1);
        if (validCode(sub)) dfs(s, start + 1, result);
        
        sub = s.substr(start, 2);
        if (validCode(sub)) dfs(s, start + 2, result);
    }
    */
    bool validCode(string& s, int start)
    {
        if (s[start] == '0') return false;
        int num = std::stoi(s.substr(start, 2));
        return num > 0 && num < 27;
    }
    
};

// dfs: TLE
// dp: 
// f1 - last number is independent
// f2 - last number is combined
// f1[i] = f1[i-1] + f2[i-1] if f1 valid
// f2[i] = f1[i1-1] if f2 valid