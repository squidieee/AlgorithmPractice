/* 
41. Maximum Subarray
Given an array of integers, find a contiguous subarray which has the largest sum.

Example
Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.

Challenge
Can you do it in time complexity O(n)?

Notice
The subarray should contain at least one number.
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        if (nums.empty()) return 0;

        // compute the prefix sum PS for each number from 0:n-1
        // the sub sum max = max(PS[j] - PS[i]) with j > i 
        // for each j, the local max subarray that contains j is to find min sub sum before j
        // then we find global max out of all j's local max
        
        int prefixSum(0);
        int minPrefixSum(0);
        int maxSubSum(INT_MIN);
        
        for(int i = 0; i < nums.size(); i ++)
        {
            prefixSum += nums[i]; // compute the prefix sum PS for each number from 0:n-1
            maxSubSum = std::max(maxSubSum, prefixSum - minPrefixSum);  // we find global max out of all j's local max
            minPrefixSum = std::min(minPrefixSum, prefixSum); // for each j, the local max subarray that contains j is to find min sub sum before j, not include j
        }
        
        return maxSubSum;
    }
};