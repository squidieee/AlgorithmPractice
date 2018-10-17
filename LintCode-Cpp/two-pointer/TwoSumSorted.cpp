/* 
608. Two Sum II - Input array is sorted
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

Example
Given nums = [2, 7, 11, 15], target = 9
return [1, 2]

Notice
You may assume that each input would have exactly one solution.
*/

class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        if (nums.empty()) return nums;
        
        int start(0), end(nums.size()-1);
        
        vector<int> index(2, -1);
        
        while (start < end)
        {
            int sum = nums[start] + nums[end];
            if (sum < target)
            {
                start++;
            }
            else if (sum > target)
            {
                end--;
            }
            else
            {
                index[0] = start + 1;
                index[1] = end + 1;
                return index;
            }
        }
        
        return index;
    }
};