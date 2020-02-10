/* 
42. Maximum Subarray II

Given an array of integers, find two non-overlapping subarrays which have the largest sum.
The number in each subarray should be contiguous.
Return the largest sum.

Example
Example 1:

Input:
[1, 3, -1, 2, -1, 2]
Output:
7
Explanation:
the two subarrays are [1, 3] and [2, -1, 2] or [1, 3, -1, 2] and [2].
Example 2:

Input:
[5,4]
Output:
9
Explanation:
the two subarrays are [5] and [4].
Challenge
Can you do it in time complexity O(n) ?

Notice
The subarray should contain at least one number
*/

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        // find max subarray from beginning
        vector<int> subSumBegin(nums.size());
        int currSum(0), minPre(0), maxSum(INT_MIN);
        for(int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            maxSum = max(maxSum, currSum - minPre);
            minPre = min(minPre, currSum);
            subSumBegin[i] = maxSum;
        }
        
        // find max subarray from ending
        vector<int> subSumEnd(nums.size(), INT_MIN);
        currSum = 0;
        minPre = 0;
        maxSum = INT_MIN;
        for(int i = nums.size() - 1; i >= 0 ; i--)
        {
            currSum += nums[i];
            maxSum = max(maxSum, currSum - minPre);
            minPre = min(minPre, currSum);
            subSumEnd[i] = maxSum;
        }
        
        // combine two results
        int result = INT_MIN;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            result = max(result, subSumBegin[i] + subSumEnd[i + 1]);
        }
        
        return result;
    }
};