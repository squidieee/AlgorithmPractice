/* 
680. Split String
Give a string, you can choose to split the string after one character or two adjacent characters, and make the string to be composed of only one character or two characters. Output all possible results.

Example
Given the string "123"
return [["1","2","3"],["12","3"],["1","23"]]
*/

class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
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
    
    // take a char or two chars from s, add it into subset, 
    // push the subset into result if there no char from s any more, 

    void dfsRecur(string& s, int start, vector<string>& subset, vector<vector<string>>& result)
    {
        // if beyond leaves
        if (start > s.size() - 1)
        {
            result.push_back(subset);
            return;
        }
        
        // add s[start] to subset
        subset.push_back(s.substr(start, 1));
        dfsRecur(s, start + 1, subset, result);
        subset.pop_back();
        
        // add s[start~start+1] to subset if exist
        if (start < s.size() - 1)
        {
            subset.push_back(s.substr(start, 2));
            dfsRecur(s, start + 2, subset, result);
            subset.pop_back();
        }
    }
    
};