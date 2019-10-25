/* 
1296. Maximum Product of Word Lengths

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example
Example1

Input: ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Output: 16
Explanation:
The two words can be "abcw", "xtfn"
Example2

Input: ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Output: 4
Explanation:
The two words can be "ab", "cd".
*/

class Solution {
public:
    /**
     * @param words: a string array
     * @return: the maximum product
     */
    int maxProduct(vector<string> &words) {
        if (words.size() < 2) return 0;
        
        // compute const conversion map
        unordered_map<char, int> map;
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            int bit = ch - 'a';
            map[ch] = 1 << bit;
        }
        
        // convert
        vector<int> nums(words.size());
        for(int i = 0; i < words.size(); i++)
        {
            nums[i] = convertWordToNumber(words[i], map);
        }
        
        // find maxProduct
        int maxProLen = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if( (int) (nums[i] & nums[j]) == 0 )
                {
                    maxProLen = max(maxProLen, (int) words[i].size() * (int) words[j].size());
                }
            }
        }
        
        return maxProLen;
    }
    
    int convertWordToNumber(const string& word, unordered_map<char, int>& map)
    {
        
        int result = 0;
        for(int i = 0; i < word.size(); i++)
        {
            // todo exception handling if invalid input char 
            
            // letter needs to be unique
            if ( (int) (result & map[word[i]]) != 0)
                continue;
                
            result += map[word[i]]; 
        }
        
        return result;
    }
};

// Sol1: hash set
// simple case:
// given two words, find if it has share letters
// store in a hash set
// Space O(n) Time O(n)
// multiple words case: assuming m words each has avg n letters
// for each word, find all words with different letters, get max product from it
// Space O(n * m) Time O(n * m + n * m * m)
