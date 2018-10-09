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
        
    }
};

