/* 
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {           
        int max_end = nums[0];
        int max_now = nums[0];
        
// dynamic programing example

        for(int i = 1;i < nums.size(); i++)
        {
            max_end = max(max_end+nums[i],nums[i]); // decide the largest sum of all subarrays ending at i
            max_now = max(max_end,max_now); // decide the global largest sum
        }
        return max_now;
    }
    

};