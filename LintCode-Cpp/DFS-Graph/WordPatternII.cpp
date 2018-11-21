/*

829. Word Pattern II
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.(i.e if a corresponds to s, then b cannot correspond to s. For example, given pattern = "ab", str = "ss", return false.)

Example
Given pattern = "abab", str = "redblueredblue", return true.
Given pattern = "aaaa", str = "asdasdasdasd", return true.
Given pattern = "aabb", str = "xyzabcxzyabc", return false.

Notice
You may assume both pattern and str contains only lowercase letters.
*/



class Solution {
public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        unordered_map<char, string> mapping;
        return dfs(pattern, 0, str, 0, mapping);
    }
    
    // take a char from pattern, check if exist in mapping
    // if yes => check if str has the substr in its beginning
    //           if yes => recursively call it with next char and next str
    //           if no => return false
    // if no => take a substr from str (for 0 : n-1) store it in mapping
    //          recursively call it with next char and next str
    //          back-trace by erasing the mapping
    //
    // exit: if pattern is end but str is not, return false
    //       if pattern is not end but str is end, return false
    //       if both are end, return true
    
    bool dfs(string &pattern, int ipa, string& str, int istr, unordered_map<char, string>& mapping)
    {
        if (ipa > pattern.size() - 1 && istr > str.size() - 1)
            return true;
        
        if (ipa > pattern.size() - 1 || istr > str.size() - 1)
            return false;
        
        bool result = false;
        
        if ( mapping.find(pattern[ipa]) != mapping.end() )
        {
            string& s = mapping.at(pattern[ipa]);
            if ( s.size() + istr > str.size() ) // exceed str len
                return false;
            
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != str[istr + i])
                    return false;
            }
            
            result = dfs(pattern, ipa + 1, str, istr + s.size(), mapping);
        }
        else
        {
            for(int len = 1; len <= str.size() - istr; len++)
            {
                string s = str.substr(istr, len);
                if ( existPattern(s, mapping) )
                    continue;
                mapping.insert({pattern[ipa], s});
                result = result || dfs(pattern, ipa + 1, str, istr + len, mapping);
                mapping.erase(pattern[ipa]);
            }
        }
        
        return result;
    }
    
    bool existPattern(string& s, unordered_map<char, string>& mapping)
    {
        for(auto it = mapping.begin(); it != mapping.end(); it++)
        {
            if (compareString(it->second, s)) return true;
        }
        return false;
    }
    
    bool compareString(string& s1, string& s2)
    {
        if (s1.size() != s2.size()) return false;
        
        for(int i = 0; i < s1.size(); i++)
        {
            if (s1[i]!=s2[i]) return false;
        }
        return true;
    }
};