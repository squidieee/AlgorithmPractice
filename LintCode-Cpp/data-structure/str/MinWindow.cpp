/* 
32. Minimum Window Substring
Given a string source and a string target, find the minimum window in source which will contain all the characters in target.

Example
For source = "ADOBECODEBANC", target = "ABC", the minimum window is "BANC"

Challenge
Can you do it in time complexity O(n) ?

Clarification
Should the characters in minimum window has the same order in target?

Not necessary.
Notice
If there is no such window in source that covers all characters in target, return the emtpy string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in source.
The target string may contain duplicate characters, the minimum window should cover all characters including the duplicate characters in target.
*/

class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
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
};

// hash map: <char, int>
// min: target.size()

// start, end
// given a start, we can find an end, or not exist
// then start++
// move end again from start
// repeated computation
// pre-process: record indices that have the target char
// then we move start and end with respect to this index array instead
