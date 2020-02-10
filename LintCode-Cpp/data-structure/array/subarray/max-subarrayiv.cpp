/* 
620. Maximum Subarray IV

Given an integer arrays, find a contiguous subarray which has the largest sum and length should be greater or equal to given length k.
Return the largest sum, return 0 if there are fewer than k elements in the array.

Example
Example 1:

Input:
[-2,2,-3,4,-1,2,1,-5,3]
5
Output:
5
Explanation:
[2,-3,4,-1,2,1]
sum=5
Example 2:

Input:
[5,-10,4]
2
Output:
-1
Notice
Ensure that the result is an integer type.
k > 0

*/

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param k: an integer
     * @return: the largest sum
     */
    
    int maxSubarray4(vector<int> &nums, int k) {
        if(nums.size() < k) return 0;
        
        int minPre(0), maxSumk(INT_MIN);
        vector<int> preSums(nums.size() + 1, 0);
        for(int i = 1; i < nums.size() + 1; i++)
        {
            preSums[i] = preSums[i - 1] + nums[i - 1];
            if(i < k) continue;
            minPre = min(minPre, preSums[i - k]);
            maxSumk = max(maxSumk, preSums[i] - minPre);
        }
        
        return maxSumk;
    }
    
    /*FIRST PASS*/
    /*
    int maxSubarray4(vector<int> &nums, int k) {
        if (nums.size() < k || k < 1) return 0;
        
    
        vector<int> PrefixSum(nums.size(), 0);
        PrefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            PrefixSum[i] = PrefixSum[i-1] + nums[i];
        }
        
        int minPrefixSum = 0;
        int maxSum = PrefixSum.back();
        
        for(int i = k - 1; i < nums.size(); i++)
        {
            maxSum = max(PrefixSum[i] - minPrefixSum, maxSum);
            minPrefixSum = min(PrefixSum[i - k + 1], minPrefixSum);
        }
        
        return maxSum;
    }
    */
};

// compute the prefix sum
// Given index i, assuming we want the largest prefix sum for all nums before i
// index i as a candidate, can be either start or end:
// if it is an end, global max = prefixSum_i - minPrefixSum
// if it is a start, prefixSum_i < minPrefixSum
// the difference of this problem is just that choosing the minPrefixSum is constrained
// such that the index of minPrefixSum should be <= i - k 