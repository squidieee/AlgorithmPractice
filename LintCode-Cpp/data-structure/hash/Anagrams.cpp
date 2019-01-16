/* 
171. Anagrams
Given an array of strings, return all groups of strings that are anagrams.

Example
Given ["lint", "intl", "inlt", "code"], return ["lint", "inlt", "intl"].

Given ["ab", "ba", "cd", "dc", "e"], return ["ab", "ba", "cd", "dc"].

Challenge
What is Anagram?

Two strings are anagram if they can be the same after change the order of characters.
Notice
All inputs will be in lower-case
*/

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        if (strs.size() < 2) return vector<string>();
        
        unordered_map<string, string> memo; // each pattern 26-size array
        vector<string> result;

        for(int i = 0; i < strs.size(); i++)
        {
            // countLetters
            vector<int> pattern = countLetters(strs[i]);
            // convert to key
            string key = createKey(pattern);
            cout << key << endl;
            // check if it exists
            if(memo.find(key) != memo.end())
            {
                if (memo.at(key) != "*")
                {
                    result.push_back(memo.at(key));
                    memo.at(key) = "*";
                }
                result.push_back(strs[i]);
            }
            else// if not, push it into patterns
            {
                memo.insert({key, strs[i]});
            }
        }
        
        return result;
    }
    
    vector<int> countLetters(string& str)
    {
        vector<int> pattern(26, 0);
        for(int i = 0; i < str.size(); i++)
        {
            pattern[str[i] - 'a']++;
        }
        
        return pattern;
    }
    
    string createKey(vector<int>& pattern)
    {
        string key;
        for(int i = 0; i < pattern.size(); i++)
        {
            if (pattern[i] != 0)
            {
                char ch = 'a' + i;
                key = key + ch + std::to_string(pattern[i]);
            }
        }
        
        if (key == "") key = "0";
        return key;
    }
};

// record pattern in a vector
// for each str, count the number of letter appears and record it in patterns
// hash set -> generate the key!
// convert to int as key? same key
// convert to str: "a5b2" 