/* 
582. Word Break II
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Example
Gieve s = lintcode,
dict = ["de", "ding", "co", "code", "lint"].

A solution is ["lint code", "lint co de"].
*/

class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
       vector<string> result;
       unordered_map<string, vector<string>> memo;
       
       if (wordDict.empty()) return result; 
       
       return dfsRecur(s, wordDict, memo);
    }
    
    // take a substr from s, add it to subset if it exists in dict, add a space after
    // if reach the end of s, remove the last substr which is a space, push it to the result
    // memorize all substr, check if it has been computed before
    vector<string> dfsRecur(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& map)
    {
        vector<string> result;
        // reach the end
        if (s.empty())
            return result;
        // if previously computed 
        if (map.find(s) != map.end())
            return map.at(s);
        
        for(int end = 0; end < s.size(); end++)
        {
            string sub = s.substr(0, end + 1);
            if (dict.find(sub) == dict.end())
                continue;
            
            // move to the rest of s
            vector<string> nextResult;
            if (end != s.size() - 1)
            {
                nextResult = dfsRecur(s.substr(end + 1, s.size() - end - 1), dict, map);
                for(int i = 0; i < nextResult.size(); i++)
                {
                    result.push_back(sub + " " + nextResult[i]);
                }                
            }
            else
                 result.push_back(sub);
        }
        
        // memroize the result
        map.insert({s, result});
        return result;
    }
};