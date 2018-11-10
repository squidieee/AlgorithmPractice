/*
52. Next Permutation
Given a list of integers, which denote a permutation.

Find the next permutation in ascending order.

Example
For [1,3,2,3], the next permutation is [1,3,3,2]

For [4,3,2,1], the next permutation is [1,2,3,4]

Notice
The list may contains duplicate integers.
*/



 class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        
       if (nums.empty()) return nums;
       
       // find the first location i where nums[i-1] < nums[i]
       int i = nums.size() - 1;
       while (i > 0 && nums[i-1] >= nums[i])
       {
           i--;
       }
       
       // if i == 0 return the reversed nums
       if (i != 0)
       // otherwise from the end find the first nums[j] > nums[i - 1]
       {
           int j = nums.size() - 1;
           while(nums[j] <= nums[i-1]) 
           {
                j--;
           }
           std::swap(nums[j], nums[i-1]);
           
       }
       
       reverse(nums, i, nums.size()-1);
       return nums;
       
    }
    
    void reverse(vector<int> &nums, int start, int end)
    {
        while(end > start)
        {
            std::swap(nums[end], nums[start]);
            start++;
            end--;
        }
    }
};