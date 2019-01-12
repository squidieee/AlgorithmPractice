/* 
13. Implement strStr()
For a given source string and a target string, you should output the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.

Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.

Challenge
O(n2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)

Clarification
Do I need to implement KMP Algorithm in a real interview?

Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure you confirm with the interviewer first.

*/

class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        // Write your code here
        
        // ver1: O(n2)
        /*
        if (target.empty()) return 0;
        if (source.empty() || target.empty()) return -1;
        if (source.length() < target.length()) return -1;
        
        
        for(int si = 0; si < source.length(); si ++)
        {
            int ti = 0;
            while(si + ti < source.length())  
            {
                if (source[si + ti] == target[ti])
                    ti++;
                else
                    break;
                if (ti == target.length()) return si;
            }
        }
        
        return -1;
        */
        // ver 2: KMP
        if (target.empty()) return 0;
        if (source.empty() || target.empty()) return -1;
        if (source.length() < target.length()) return -1;
        
        vector<int> prefixTable(target.size(), 0);
        unordered_map<char, int> map;
        // compute prefix table
        for(int i = 0; i < target.size(); i++)
        {
            if(map.find(target[i]) == map.end())
            {
                map.insert({target[i], i});
                prefixTable[i] = 0;
            }
            else
            {
                prefixTable[i] = map.at(target[i]) + 1;
                map.at(target[i]) = i;
            }
        }
        
        // compare
        int si = 0;
        while(si <= source.size() - target.size())
        {
            for(int ti = 0; ti < target.size(); ti++)
            {
                if (source[si + ti] != target[ti])
                {
                    // shift si by prefix
                    si += prefixTable[ti];
                    break;
                }
                
                if (ti == target.size() - 1) return si;
            }
            si++;
        }
        
        return -1;
    }
};

