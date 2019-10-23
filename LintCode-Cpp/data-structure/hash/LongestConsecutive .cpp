/* 
124. Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Clarification
Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        if (num.size() < 2) return num.size();
        
        // first pass
        unordered_set<int> set(num.begin(), num.end());
        
        // second pass
        int MAXLEN = 1;
        for (auto val : num)
        {
            if (set.find(val) != set.end())
            {
                set.erase(val);
                int left = val - 1;
                int right = val + 1;
                
                while(set.find(left) != set.end())
                {
                    set.erase(left);
                    left--;
                }
                
                while(set.find(right) != set.end())
                {
                    set.erase(right);
                    right++;
                } 
                MAXLEN = std::max(MAXLEN, right - left - 1);
            }
        }

        
        return MAXLEN;

    }
};

// brutal force:
// sort it first, then do a linear pass to see whether it increases consecutively
// O(nlogn) + O(n) = O(nlogn)

// O(n) Time:
// keep a hash set
// 1st pass: store all number into the set
// 2nd pass: for each num, see if num-1 or num+1 exists in the table, if so:
//           continue finding num-2 and num + 2 etc... 
//           each time found it, erase it from the set

// O(n) space