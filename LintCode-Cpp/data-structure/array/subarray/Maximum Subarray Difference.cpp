/* 
45. Maximum Subarray Difference

Given an array with integers.

Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest.

Return the largest difference.

Example
Example 1:

Input:[1, 2, -3, 1]
Output:6
Explanation:
The subarray are [1,2] and [-3].So the answer is 6.
Example 2:

Input:[0,-1]
Output:1
Explanation:
The subarray are [0] and [-1].So the answer is 1.
Challenge
O(n) time and O(n) space.

Notice
The subarray should contain at least one number
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two substrings
     */
    int maxDiffSubArrays(vector<int> &nums) {
        int res1 = helper(nums, false);
        int res2 = helper(nums, true);
        return max(res1, res2);
    }
    
    int helper(vector<int> &nums, bool reverse)
    {
        // forward
        vector<int> maxSumArray(nums.size(), 0);
        int minPreSum(0),currSum(0), maxSum(INT_MIN);
        for(int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i] * (reverse? -1:1);
            maxSum = max(maxSum, currSum - minPreSum);
            minPreSum = min(minPreSum, currSum);
            maxSumArray[i] = maxSum * (reverse? -1:1);
        }
        
        // backward
        vector<int> minSumArray(nums.size() + 1, INT_MIN);
        minPreSum = 0;
        currSum = 0;
        maxSum = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            currSum += nums[i] * (reverse? 1:-1);
            maxSum = max(maxSum, currSum - minPreSum);
            minPreSum = min(minPreSum, currSum);
            minSumArray[i] = maxSum * (reverse? 1:-1);
        }
        
        
        // combine two arrays
        int result = INT_MIN;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            result = max(result, abs(maxSumArray[i] - minSumArray[i + 1]));
        }
        
        return result;        
    }
};