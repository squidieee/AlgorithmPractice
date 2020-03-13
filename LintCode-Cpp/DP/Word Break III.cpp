/* 
683. Word Break III

Give a dictionary of words and a sentence with all whitespace removed, return the number of sentences you can form by inserting whitespaces to the sentence so that each word can be found in the dictionary.

Example
Example1

Input:
"CatMat"
["Cat", "Mat", "Ca", "tM", "at", "C", "Dog", "og", "Do"]
Output: 3
Explanation:
we can form 3 sentences, as follows:
"CatMat" = "Cat" + "Mat"
"CatMat" = "Ca" + "tM" + "at"
"CatMat" = "C" + "at" + "Mat"
Example1

Input:
"a"
[]
Output: 0
Notice
Ignore case
*/

class Solution {
public:
    /*
     * @param : A string
     * @param : A set of word
     * @return: the number of possible sentences.
     */
    int wordBreak3(string& s, unordered_set<string>& dict) {
        if(s.empty()) return 0;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        unordered_set<string> nml_dict;
        for(string word: dict)
        {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            nml_dict.insert(word);
        }
        
        vector<int> dp(s.size(),  0);
        dp[0] = nml_dict.find(s.substr(0,1)) == nml_dict.end()? 0:1;
        for(int end = 1; end < s.size(); end++)
        {
            if(nml_dict.find(s.substr(0, end + 1)) != nml_dict.end()) dp[end] = 1;
            
            for(int k = 0; k < end; k++)
            {
                if(nml_dict.find(s.substr(k+1, end - k)) != nml_dict.end())  dp[end] += dp[k];
            }
        }
        
        return dp.back();
    }
    
};

// dp[i] is the number of combinations for a substring of s from 0 to i
// dp[i] = sum(dp[k]) for all k < i when the substr of s from k+1 to i can be found in dict
// dp[i]++ when the substr itself is also in dict