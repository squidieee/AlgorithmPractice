/* 
31. Partition Array
Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:

All elements < k are moved to the left
All elements >= k are moved to the right
Return the partitioning index, i.e the first index i nums[i] >= k.

Example
If nums = [3,2,2,1] and k=2, a valid answer is 1.

Challenge
Can you partition the array in-place and in O(n)?

Notice
You should do really partition in array nums instead of just counting the numbers of integers smaller than k.

If all elements in nums are smaller than k, then return nums.length
*/


class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if (nums.empty()) return 0;
        int left(0), right(nums.size()-1);
        
        while(left <= right)
        {
            while(left <= right && nums[left] < k)
            {
                left++;
            }
            while(left <= right && nums[right] >= k)
            {
                right--;
            }
            
            if (left <= right)
            {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
         return left;
    }
   
};