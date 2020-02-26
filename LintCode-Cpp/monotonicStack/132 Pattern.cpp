/* 
636. 132 Pattern

Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

n will be less than 20,000.

Example
Example 1:

Input: nums = [1, 2, 3, 4] 
Output: False 
Explanation:
There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3, 1, 4, 2] 
Output: True 
Explanation:
There is a 132 pattern in the sequence: [1, 4, 2].

*/

class Solution {
public:
    /**
     * @param nums: a list of n integers
     * @return: true if there is a 132 pattern or false
     */
    bool find132pattern(vector<int> &nums) {
        if(nums.empty()) return false;
        
        int second = INT_MIN;
        stack<int> stk;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(nums[i] < second) return true;
            
            while(!stk.empty() && nums[i] > stk.top())
            {
                second = stk.top();
                stk.pop();
            }
            
            stk.push(nums[i]);
        }
        
        return false;
    }
};