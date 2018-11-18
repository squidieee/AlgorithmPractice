/*
10. String Permutation II
Given a string, find all permutations of it without duplicates.

Example
Given "abb", return ["abb", "bab", "bba"].

Given "aabb", return ["aabb", "abab", "baba", "bbaa", "abba", "baab"].
*/


class Solution {
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    vector<string> stringPermutation2(string &str) {
        vector<string> result;
        if (str.empty())
        {
            result.push_back("");
            return result;
        }
        
        std::sort(str.begin(), str.end());
        
        vector<bool> visited(str.size(), false);
        string subset;
        
        dfs(str, visited, subset, result);
        
        return result;
    }
    
    // take a char from str, add it to subset if not visited and not repeated
    // if subset.size() == str.size(), add it to results
    
    void dfs(string& str, vector<bool>& visited, string& subset, vector<string>& results)
    {
        for( int i = 0; i < str.size(); i++)
        {
            if (visited[i])
                continue;
            
            if (i > 0 && str[i] == str[i-1] && !visited[i-1])
                continue;
            
            subset.push_back(str[i]);
            visited[i] = true;
            
            if (subset.size() == str.size())
            {
                results.push_back(subset);
            }
            else
            {
                dfs(str, visited, subset, results);
            }
            
            subset.pop_back();
            visited[i] = false;
        }
    }
};