/* 
138. Subarray Sum
Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.

Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].

Notice
There is at least one subarray that it's sum equals to zero.
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // divide and conquer
        // [0] -> return [0,0]
        // [.., -1] -> return [i,i] or [prev, i]
        // [prev, i]: only valid if subSum == -nums[i], so need to know save all subarraies for nums[i-1] and update it for new nums[i]
        // for O(1) match, use hash map, but key needs to be updated for each i
        
        // prefix Sum: when sub array == 0 -> find same perfix Sum
        // example: [-3, 1, 2, -3]
        //       [0, -3,-2, 0, -3]
        // hash map to store prefix
        
        vector<int> result;
        if (nums.empty()) return result;
        
        // compute the prefix sum O(n) Time and O(n) Space
        unordered_map<int,int> prefixSum;
        prefixSum.insert({0,0});
        
        int sum = 0;
        for(int i = 0; i < nums.size();i++)
        {
            sum += nums[i];
            if (prefixSum.find(sum)!=prefixSum.end()) // find one
            {
                result.push_back(prefixSum.at(sum));
                result.push_back(i);
                return result;
            }
            else // not find one
            {
                prefixSum.insert({sum, i + 1});
            }
        }
        
        return result;
        
    }
};