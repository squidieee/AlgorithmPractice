/*
425. Letter Combinations of a Phone Number
Given a digit string excluded 01, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
*/



class Solution {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        vector<string> results;
        if (digits.empty()) return results;
        
        string subset;
        vector<string> table{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(digits, 0, subset, results,table);
        return results;
    }
    
    
    // take one number from digits, for each of its possible letter, add it to subset
    // if subset.size() == digits.size(), add to results
    // otherwise call next level
    void dfs(string &digits, int index, string& subset, vector<string>& results, vector<string>& table)
    {
        if (index > digits.size() - 1)
            return;
        
        int number = digits[index] - '2';

        for(int i = 0; i < table[number].size(); i++)
        {
            char c = table[number][i];
            subset.push_back(c);
            
            if (subset.size() == digits.size())
            {
                results.push_back(subset);
            }
            else
            {
                dfs(digits, index + 1, subset, results, table);
            }
            
            subset.pop_back();
        }
    }
};