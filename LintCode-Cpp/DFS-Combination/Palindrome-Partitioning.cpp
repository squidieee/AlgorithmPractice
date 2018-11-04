/* 
136. Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example
Given s = "aab", return:

[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
         vector<vector<string>> result;
         vector<string> subset;
         
         if (s.empty())
         {
             result.push_back(subset);
             return result;
         }
         
         dfsRecur(s, 0, subset, result);
         return result;
    }
    
    // take a substring from s, if isPalindrome, add it into subset, recursively call start + 1;
    // if not, do nothing.
    // if no more substring, push the subset into result
    void dfsRecur(string& s, int start, vector<string>& subset, vector<vector<string>>& result)
    {
        // if reach the end
        if (start > s.size() - 1)
        {
            result.push_back(subset);
            return;
        }
        
        // for all children under this node: all substr that contains s[start]
        for(int end = start; end < s.size(); end++)
        {
            string sub = s.substr(start, end - start + 1); // since string needs to be constructed for each iter, it takes longer to compute
                                                           // this can be improved with isPalindrome[][] array + vector<int> partition
                                                           // and construct the string result only when the last step: start > s.size() - 1
            if ( !isPalindrome( sub ) )
                continue;
            
            subset.push_back (sub);
            dfsRecur(s, end + 1, subset, result);
            subset.pop_back();
        }
    }
    
    bool isPalindrome(string& s)
    {
        int start(0), end(s.size() - 1);
        while(start <= end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};