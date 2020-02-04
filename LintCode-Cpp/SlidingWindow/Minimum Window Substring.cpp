/* 
32. Minimum Window Substring

Given two strings source and target. Return the minimum substring of source which contains each char of target.

Example
Example 1:

Input: source = "abc", target = "ac"
Output: "abc"
Example 2:

Input: source = "adobecodebanc", target = "abc"
Output: "banc"
Explanation: "banc" is the minimum substring of source string which contains each char of target "abc".
Example 3:

Input: source = "abc", target = "aa"
Output: ""
Explanation: No substring contains two 'a'.
Challenge
O(n) time

Notice
If there is no answer, return "".
You are guaranteed that the answer is unique.
target may contain duplicate char, while the answer need to contain at least the same number of that char.

*/

class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        if(target.empty() || source.empty()) return "";
        
        unordered_map<char, int> charMap;
        for(char ch: target)
        {
            charMap[ch]++;
        }
        
        int start = 0;
        int charToMatch = charMap.size();
        int len = INT_MAX;
        string restr = "";
        for(int end = 0; end < source.size(); end++)
        {
            if(charMap.find(source[end])!=charMap.end())
            {
                charMap[source[end]]--;
                if(charMap[source[end]] == 0) charToMatch--;
            }
            
            while(charToMatch == 0)
            {
                if(charMap.find(source[start]) != charMap.end())
                {
                    charMap[source[start]]++;
                    if(charMap[source[start]] > 0) charToMatch++;
                }
                if(charToMatch > 0 && len > end - start + 1)
                {
                    len = end - start + 1;
                    restr = source.substr(start, len);
                }
                start++;
            }
        }
        
        return restr;
     }


/* FIRST PASS */
/*
    string minWindow(string &source , string &target) {
        if (source.empty() || target.empty()) return "";
        
        // build the target table
        unordered_map<char, int> table;
        for(int i = 0; i < target.size(); i++)
        {
            if (table.find(target[i])!=table.end())
            {
                table.at(target[i])++;
            }
            else
            {
                table.insert({target[i], 1});
            }
        }
        // record all indices
        vector<int> indices;
        for(int i = 0; i < source.size(); i++)
        {
            if(table.find(source[i])!=table.end())
            {
                indices.push_back(i);
            }
        }
        // make a pass on indices
        int cnt(0);
        int minLen = source.size() + 1;
        int left = 0;
        string result;
        
        for(int i = 0; i < indices.size(); i++)
        {
            table.at(source[indices[i]])--;
            if (table.at(source[indices[i]]) == 0)
            {
                cnt++;
            }

            // keep moving the left of window when all targets are included 
            // until we need new data to form a min set
            while (cnt == table.size())
            {
                if (minLen > indices[i] - indices[left] + 1)
                {
                    minLen = indices[i] - indices[left] + 1;
                    result = source.substr(indices[left], minLen);
                }
                // move left
                table.at(source[indices[left]])++;
                if (table.at(source[indices[left]]) > 0)
                    cnt--;
                left++;
            }
        }
        
        return result;
    }
 */
};

/* FIRST PASS NOTES */

// hash map: <char, int>
// min: target.size()

// start, end
// given a start, we can find an end, or not exist
// then start++
// move end again from start
// repeated computation
// pre-process: record indices that have the target char
// then we move start and end with respect to this index array instead