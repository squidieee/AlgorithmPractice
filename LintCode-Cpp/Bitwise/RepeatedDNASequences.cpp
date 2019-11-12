/* 
1335. Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example
Example1

Input: "A"
Output: []
Example2

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/

class Solution {
public:
    /**
     * @param s: a string
     * @return: return List[str]
     */
    vector<string> findRepeatedDnaSequences(string &s) {

        vector<string> result;
        if (s.size() < 10) return result;
        
        unordered_map<int, int> map;
        unordered_map<char, int> letter({{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}});        
        
        int code = 0;
        for(int i = 0; i < 9; i++)  
            code = (code << 2) | letter[s[i]];
        
        for(int i = 9; i < s.size(); i++)
        {
            code = ( (code & 0x3FFFF) << 2) | letter[s[i]];
            if (map.find(code)!=map.end() && map[code] != -1)
            {
                result.push_back(s.substr(i - 9, 10));
                map[code] = -1;
            }
            else
                map.insert({code,1});
        }
        
        return result;

        
        /* // Sol2
        unordered_set<string> result;
        
        // common str len
        int len = s.size() - 1; 
        while(len > 9)
        {
            compareSubString(s, 0, (int)s.size() - len, len, result);
            len--;
        }
        
        vector<string> vecRes;
        for(auto& str: result)
        {
            vecRes.push_back(str);
        }
        
        return vecRes;
        */
    }
    
    /* // Sol2 helper: TIMEOUT
    void compareSubString(string& s, int l1, int l2, int len, unordered_set<string>& result)
    {
        int cnt = 0;
        for(int i = 0; i < len; i++)
        {
            cnt = s[l1 + i] == s[l2 + i]? cnt + 1:0;
            if(cnt > 9)
            {
                string sub = s.substr(l1 + i - 9, 10);
                if (result.find(sub) == result.end())
                    result.insert(sub);
            }
        }
    }
    */
};

// Sol1: hash set
// store all 10-letter-long seq in a hash set and compare whether the current one exists
// Time O(n) Space O(n)
// Improve: encode the 10-len to reduce storage
// Since there are four type: use 2 bits to represent a letter

// Sol2: sliding string
// Time O(n^2) -- Timeout