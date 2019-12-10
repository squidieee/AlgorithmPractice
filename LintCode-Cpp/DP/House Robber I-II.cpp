/* 
392. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example
Example 1:

Input: [3, 8, 4]
Output: 8
Explanation: Just rob the second house.
Example 2:

Input: [5, 2, 1, 3]
Output: 8
Explanation: Rob the first and the last house.
Challenge
O(n) time and O(1) memory.
*/

class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        if(A.size() == 0) return 0;
        vector<long long> fn(A.size() + 1, 0);
        fn[0] = 0;
        fn[1] = A[0];
        for(int i = 2; i < fn.size(); i++)
        {
            fn[i] = max(fn[i-1], fn[i-2] + A[i-1]);
        }
        
        return fn.back();
    }
};

/* 
534. House Robber II

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example
Example1

Input:  nums = [3,6,4]
Output: 6
Example2

Input:  nums = [2,3,2,3]
Output: 6
Notice
This is an extension of House Robber.
*/

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> &nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        return std::max(houseRobber1(nums, 0), houseRobber1(nums, 1));
    }
    
    int houseRobber1(vector<int> &nums, int start)
    {
        vector<int> fn(nums.size(), 0);
        fn[0] = 0;
        fn[1] = nums[start];
        for(int i = 2; i < fn.size(); i++)
        {
            fn[i] = max(fn[i-1], fn[i-2] + nums[start + i-1]);
        }
        return fn.back();
    }
};